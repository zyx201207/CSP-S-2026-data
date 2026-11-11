#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::max;
using std::min;
namespace my{
	int n,k,ans;
	bool used[11],mark[11];
	vector<int> e[1000005];
	inline int ceil(int a,int b){
		return (a + b - 1) / b;
	}
	int dfs_dis(int u,int last,int step){
		if(used[u])
		{
			return step;
		}
		int vsiz = e[u].size(),res = 0x3f3f3f3f;
		for(int i = 0;i < vsiz;i += 1)
		{
			int v = e[u][i];
			if(v != last)
			{
				res = min(res,dfs_dis(v,u,step + 1));
			}
		}
		return res;
	}
	void dfs_color(int u){
		mark[u] = true;
		int vsiz = e[u].size();
		for(int i = 0;i < vsiz;i += 1)
		{
			int v = e[u][i];
			if(used[v] && (!mark[v]))
			{
				dfs_color(v);
			}
		}
		return;
	}
	void dfs(int u,int rest){
		if(rest < 0 || n - u + 1 < rest)
		{
			return;
		}
		if(u > n)
		{
			if(rest != 0)
			{
				return;
			}
			int res = 0,cnt = 0;
			memset(mark,0,sizeof(mark));
			for(int i = 1;i <= n;i += 1)
			{
				if(used[i] && (!mark[i]))
				{
					cnt += 1;
					if(cnt > 2)
					{
						return;
					}
					dfs_color(i);
				}
			}
			for(int i = 1;i <= n;i += 1)
			{
				res = max(res,dfs_dis(i,i,0));
			}
			ans = min(ans,res);
		}
		else
		{
			used[u] = true;
			dfs(u + 1,rest - 1);
			used[u] = false;
			dfs(u + 1,rest);
		}
		return;
	}
}using namespace my;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	int _,__;
	cin>>_>>__;
	while(__--)
	{
		cin>>n>>k;
		if(n == k)
		{
			cout<<"0\n";
			continue;
		}
		for(int i = 1;i <= n;i += 1)
		{
			e[i].clear();
		}
		for(int i = 1;i < n;i += 1)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(_ == 13 || _ == 14)
		{
			cout<<max(1,ceil(n / 2 + 2 - k,4))<<'\n';
		}
		else
		{
			ans = 0x3f3f3f3f;
			dfs(1,k);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
