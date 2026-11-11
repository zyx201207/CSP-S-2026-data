#include<bits/stdc++.h>
using namespace std;
typedef long long lnt;
const int N = 5e5+5;
const int M = 1005;
const lnt Max = 4557430888798830399;
lnt n,m,dt,c,q,w[N];
struct road{
	int v;
	lnt w;
    bool operator>(const road& x)const{
	return w>x.w;}
};
vector<road> s[M],p[N];
lnt fd[M][M];
lnt d[M][M];
bool ins[M];
void dj(int r)
{
	memset(ins,0,sizeof(ins));
	priority_queue<road,vector<road>,greater<road> > q;
	q.push({r,0});
	while(!q.empty())
	{
		road u = q.top();
		q.pop();
		if(ins[u.v])continue;
		ins[u.v] = 1;
		for(auto v : s[u.v])
		{
			if(ins[v.v])continue;
			if(d[r][v.v]>d[r][u.v]+v.w)
			{
				d[r][v.v] = d[r][u.v] + v.w;
				q.push({v.v,d[r][v.v]});
			}
		}
	}	
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> c >> n >> m >> dt >> q;
    for(int i=1;i<=m;i++)cin >> w[i];
    for(int i=1;i<=n;i++)
    {
    lnt a, t , num;
    cin >> num;
    for(int j = 1; j<=num;j++)
    {
    	cin >> a >> t;
    	p[a].push_back({i,t});
    }
    }
    for(int i = 1; i<= n; i++)
	for(int j = 1; j<= n; j++)
	{
		if(i==j)fd[i][i]=0,d[i][i]=0;
		else fd[i][j]=Max,d[i][j]=Max;
	}
    for(int i = 1; i<= m; i++)
    {
    	for(auto u : p[i])
    	for(auto v : p[i])
    	{
    		if(u.v==v.v)continue;
    		fd[u.v][v.v] = min(fd[u.v][v.v],u.w+v.w);
    	}
    }
    for(int i = 1; i<=n;i++)
    for(int j = 1; j<=n;j++)
    if(fd[i][j]!=Max&&i!=j)
    s[i].push_back({j,fd[i][j]});
    for(int i = 1; i<= n;i++)dj(i);
    while(q--)
    {
    	lnt x ;
    	lnt y ;
    	cin >> x >> y;
    	lnt ans = Max;
    	for(auto u:p[x])
    	for(auto v:p[y])
    	ans = min(d[u.v][v.v]+u.w+v.w,ans);
    	cout << ans+w[x]+w[y] << "\n";
    }
    return 0;
} 

