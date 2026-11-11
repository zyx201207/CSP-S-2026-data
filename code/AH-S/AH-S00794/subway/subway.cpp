#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],ans,vmin=pow(2,62),f1[500005],f2[505],T=-1,f[1000005];
pair<int,int> qq[1000005];
vector<long long> a[505],t[505],edge[500005];
vector<pair<long long,long long> > e[500005];
inline void dfs(int now,int end,long long time,int line,int ex) {
	if(now==end) {
		vmin=min(vmin,time);
		return ;
	}
	f1[now]=1;
	f2[line]=1;
	if(ex==0) {
		for(int i=0;i<a[line].size();i++) {
			if(f1[a[line][i]]==1) {
				continue;
			}
			dfs(a[line][i],end,time+t[line][i],line,1);
		}
	}
	if(ex==1) {
		for(int i=0;i<e[now].size();i++) {
			if(f2[e[now][i].first]==1) {
				continue;
			}
			dfs(now,end,time+e[now][i].second,e[now][i].first,0);
		}
	}
	return ;
}
inline void bfs(int now,int end) {
	int cnt=0;
	qq[++cnt]=make_pair(now,0);
	f[now]=1;
	while(cnt>0) {
		int u=qq[cnt].first,v=qq[cnt].second;
		cnt--;
		for(int i=0;i<edge[u].size();i++) {
			if(f[edge[u][i]]==1) {
				continue;
			}
			qq[++cnt]=make_pair(edge[u][i],v+1);
			f[edge[u][i]]=1;
			if(qq[cnt].first==end)
			{
				vmin=qq[cnt].second;
				return ;
			}
		}
	}
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	int f=1;
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		for(int j=1;j<=(int)k[i];j++) {
			int x,y;
			cin>>x>>y;
			if(T=-1) {
				T=y;
			}
			else {
				if(T!=y) {
					f=0;
				}
			}
			a[i].push_back(x);
			t[i].push_back(y);
			e[x].push_back(make_pair(i,y));
		}
	}
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=(int)k[i];j++)
			{
				for(int o=j+1;o<=(int)k[i];o++)
				{
					edge[a[i][j]].push_back(a[i][o]);
					edge[a[i][o]].push_back(a[i][j]);
				}
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			bfs(x,y);
			cout<<vmin*T*2-2*T+w[x]+w[y]<<endl;
		}
		return 0;
	}
	while(q--) {
		vmin=pow(2,62);
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		for(int i=0;i<e[x].size();i++) {
			dfs(x,y,e[x][i].second,e[x][i].first,0);
			memset(f1,0,sizeof(f1));
			memset(f2,0,sizeof(f2));
		}
		cout<<vmin+ans<<endl;
	}
	return 0;
}
