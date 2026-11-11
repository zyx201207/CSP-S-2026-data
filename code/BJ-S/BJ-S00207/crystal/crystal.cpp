#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL n,m,a[N],l,r,ans,cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(LL i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=-1e18;
    a[n+1]=1e18;
    l=1;
    for(LL i=1;i<=n;i++){
        if(l<i)cnt+=(a[i]-a[i-1])*(i-l);
        while(cnt>m){
            cnt-=abs(a[l]-a[i]);
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
