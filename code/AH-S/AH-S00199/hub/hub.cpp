#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005;
int dep=-1;
vector<int> t[N];
void dfs(int fa,int u,int d)
{
	dep=max(dep,d);
	for(auto e : t[u])
	{
		if(e!=fa)
		{
			dfs(u,e,d+1);
		}
	}
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++){
			dep=-1;
			dfs(-1,i,1);
			if(dep!=-1)
				ans=min(ans,dep);
		}
		cout<<ans-k<<'\n';
	}
	return 0;
}

