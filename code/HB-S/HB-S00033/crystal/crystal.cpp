#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N=5e5+10;
const ll MAXN=1e13;
int n,a[N],k,ans=0;ll cost[N]; bool isd=1; 
ll m;
void init()
{
    for(int i=2;i<=n;++i) cost[i]=MAXN;
}
int dc()
{
    ll d[n]={0},sum[n]={0};int ansc=0;
    for(int i=1;i<=n-1;++i) d[i]=1LL*i*k;
    for(int i=1;i<=n-1;++i) {
        sum[i]=d[i]+sum[i-1];
        if(sum[i-1]<=m&&m<sum[i]) {ansc=i;break;}
        if(i==n-1&&m>=sum[i]){ansc=i;break;}
    }
    return ansc;
}
int solve1()
{
    init();
    int x=0,tag=0;ll sum[n]={0};
    for(int i=1;i<=n-1;++i)
    {
        sum[i]=0;
        for(int j=i+1;j<=n;++j)
        {
            x=a[i]-a[j];
            sum[j]=sum[j-1]+x;
            cost[j-i+1]=min(cost[j-i+1],sum[j]);
        }
    }
    for(int i=2;i<=n;++i) if(cost[i]<=m) tag=i;
    return tag;
}
bool cmp(int x,int y){return x>y;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) {
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=k) isd=0;
        if(i>1) k=a[i]-a[i-1];
    }
    // sp A B
    if(isd) {sort(a+1,a+n+1); ans=dc();}
    else {sort(a+1,a+n+1,cmp);ans=solve1();}
    cout<<ans; // 70pts
    return 0;
}