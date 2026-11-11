#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
ifstream fin("hub.in");
ofstream fout("hub.out");
#define cin fin
#define cout fout
vector<int>g[1000001];
int mx;
void dfs(int now,int last,int dep)
{
	mx=max(mx,dep);
	for(auto next:g[now])
		if(next!=last)
			dfs(next,now,dep+1);
}
int main()
{
	ios::sync_with_dtsio(0);
	cin.tie(0);
	int n,c,T,k;
	cin>>c>>T;
	while(T--)
	{
		mx=0;
		cin>>n,k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0,1);
		cout<<mx<<endl;
		for(int i=1;i<=n;i++)
			g[i].resize(0);
	}
	
}
