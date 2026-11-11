#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const ll F=0xffffffff;
ll n,m,ans,maxn,ans1=F,dp[N];
bool f=1;
struct node{
    ll x,p;
}a[N];
ll pc(ll x){
    ll cnt=0;
    while(x){
        x=x&(x-1);
        cnt++;
    }return cnt;
}
bool cmp(node x,node y){
    return x.p!=y.p?x.p>y.p:x.x>y.x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].p=pc(a[i].x);
        maxn=max(maxn,a[i].x);
        ans1&=a[i].x;
        if(a[i].x!=i-1)f=0;
    }if(m==1){cout<<maxn<<'\n';return 0;}
    if(m==n){cout<<ans1<<'\n';return 0;}
    if(f==1){
        memset(dp,0xff,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]&a[i].x);
            }
        }cout<<dp[m]<<'\n';
        return 0;
    }
    // for(int i=1;i<=n;i++)cout<<a[i].x<<' '<<a[i].p<<'\n';
    sort(a+1,a+n+1,cmp);
    // for(int i=1;i<=n;i++)cout<<a[i].x<<' '<<a[i].p<<'\n';
    ans=a[1].x;
    for(ll i=2;i<=m;i++)ans&=a[i].x;
    cout<<ans<<'\n';
    return 0;
}