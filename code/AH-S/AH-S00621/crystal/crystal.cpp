#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500500],l=0,r=0,yu=0,ans=0;
int n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    yu=m;
    l=n;
    sort(a+1,a+n+1);
    for(int i=n;i>0;i--){
        r=i;
        while(yu>=a[i]-a[l]&&l>0){
            yu-=a[i]-a[l];
            l--;
        }
        ll o=r-l;
        ans=max(ans,o);
        ll p=a[i]-a[i-1];
        yu+=o*p;
    }
    cout<<ans;

    return 0;
}