#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=(a);i>=(int)(b);i--)
#define all(v) v.begin(),v.end()
#define lb(x) ((x) & -(x))
#define clz(x) __builtin_clz(x)
#define lg(x) (clz(1)-clz(x))
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define siz(x) ((int)x.size())
using namespace std;
const int N=5e5+10;
int n,m,a[N],pre[N],ans;
int getl(int r)
{
    int L=1,R=r,res=r+1;
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if(a[r]*(r-mid+1)-(pre[r]-pre[mid-1])<=m) res=mid,R=mid-1;
        else L=mid+1;
    }
    return res;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep(i,1,n) pre[i]=pre[i-1]+a[i];
    rep(i,1,n) ans=max(ans,i-getl(i)+1);
    cout<<ans<<"\n";
    return 0;
}

