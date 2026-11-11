#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5;
int c,m,n,d,q;
int w[MAXN+5];
int k[505];
int a[505][MAXN+5];
int t[505][MAXN+5];
int jl[505];
struct node{
    int nd,to,wt;
};
vector<node> dg[MAXN+5];
vector<int> g[MAXN+5];
void dfs(int u,int ed,int xll,ll sum)
{
    return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            dg[a[i][j]].push_back({i,t[i][j]});
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k[i];j++)
        {
            g[a[i][j-1]].push_back(a[i][j]);
            g[a[i][j]].push_back(a[i][j-1]);
        }
    }
    while(q--)//On^3
    {
        int x,y;
        cin>>x>>y;
        int ans=w[x]+w[y];
        cout<<ans<<endl;
    }
	return 0;
}














