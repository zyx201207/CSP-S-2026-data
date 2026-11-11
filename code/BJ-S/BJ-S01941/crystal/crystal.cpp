#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll i=1,need=0;
    for(int j=1;j<=n;j++){
        need+=(a[j]-a[j-1])*(j-i);
        while(need>m){
            need-=a[j]-a[i];
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}
