#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        int l=0,r=i-1,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(s[i-1]-s[mid]+m>=a[i]*(i-mid-1)) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l);
    }
    cout<<ans;
    return 0;
}