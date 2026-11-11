#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,x,y) for(i=x;i<=y;i++)
#define rF(i,x,y) for(i=x;i>=y;i--)
const int N=5e5+5,MOD=1e9+7;
typedef pair<int,int> PII;
int n,m,a[N],sz[N],ans[N],lst[N];
vector<int> v[N];   
void dfs(int x)
{
    for(auto to:v[x])
    {
        dfs(to);
        sz[x]+=sz[to];
    }
    sz[x]++,ans[a[x]]+=sz[x];
    return ;
}
void solve()
{
    cin>>n>>m;
    int i;
    F(i,1,n) cin>>a[i];
    lst[a[n]]=n-1;
    rF(i,n-1,1) 
    {
        if(!lst[a[i]]) lst[a[i]]=i;
        v[lst[a[i]]+1].push_back(i);
    }
    dfs(n);
    ans[a[n]]=n;
    F(i,1,m) cout<<ans[i]<<' ';
    return;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0),cin.tie(0);
    int T=1;
    // cin>>T;
    while(T--) {solve();}
}