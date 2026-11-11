#include<bits/stdc++.h>
using namespace std;
//地铁是双向任意通行 
const int N=5e5+10;
int c, n, m, d, q;
int w[N], k;
int a;
vector<int>t[510];
int num[510][N];
vector<int>v1[N];
long long dis[510][510];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)
		cin>>w[i];
	memset(dis, 0x3f, sizeof dis);
	for(int i=1; i<=n; i++) {
		dis[i][i]=0;
		cin>>k;
		t[i].push_back(0); 
		for(int j=1; j<=k; j++) {
			int x;
			cin>>a>>x;
			t[i].push_back(x);
			num[i][a]=j;
			v1[a].push_back(i);
		}
	}

	for(int i=1; i<=m; i++) 
		for(int j=0; j<v1[i].size(); j++)
			for(int k=0; k<v1[i].size(); k++)
			{
				int a=v1[i][j], b=v1[i][k];
				dis[a][b]=min(dis[a][b], 1ll*t[a][num[a][i]]+1ll*t[b][num[b][i]]);
				dis[b][a]=min(dis[b][a], 1ll*t[a][num[a][i]]+1ll*t[b][num[b][i]]);
			}

	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
	for(int i=1; i<=q; i++)
	{
		int s1, t1;
		cin>>s1>>t1;
		long long ans=1e18;
		for(int i=0; i<v1[s1].size(); i++)
			for(int j=0; j<v1[t1].size(); j++)
			{
				int a=v1[s1][i], b=v1[t1][j];
				long long dist=dis[a][b]+w[s1]+w[t1]+t[a][num[a][s1]]+t[b][num[b][t1]];
				if(ans>dist)
					ans = dist;
			}
		cout<<ans;
		if(i!=q) cout<<"\n";
	}
	return 0;
}
