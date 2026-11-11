#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::max;
using std::sort;
using std::greater;
namespace my{
	struct Edge{
		int v,w;
	};
	struct NodeQ{
		long long w;
		int u;
		bool operator > (const NodeQ &n) const{
			return w > n.w;
		}
	};
	int n,dis[305],cnt[305];
	long long d,a[2000005],ans;
	vector<int> e[305];
	void dfs(int u,int step){
		if(dis[u] < step)
		{
			return;
		}
		if(dis[u] > step)
		{
			dis[u] = step;
			cnt[u] = 0;
		}
		cnt[u] += 1;
		int vsiz = e[u].size();
		for(int i = 0;i < vsiz;i += 1)
		{
			int v = e[u][i];
			dfs(v,step + 1); 
		}
	}
}using namespace my;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	int _,__;
	cin>>_>>__;
	while(__--)
	{
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i += 1)
		{
			cin>>a[i];
		}
		if(_ <= 6)		//n <= 300，建图暴力找 
		{
			for(int i = 1;i <= n;i += 1)
			{
				e[i].clear();
				for(int j = i + 1;j <= n;j += 1)
				{
					if(a[j] - a[i] <= d)
					{
						e[i].emplace_back(j);
					}
					else
					{
						break;
					}
				}
				sort(e[i].begin(),e[i].end(),greater<int>());
			}
			for(int i = 1;i <= n;i += 1)
			{
				memset(dis,0x3f,sizeof(dis));
				memset(cnt,0,sizeof(cnt));
				dfs(i,0);
				for(int j = i + 1;j <= n;j += 1)
				{
					if(cnt[j] == 2)
					{
						ans += 1;
					}
				}
			}
			cout<<ans<<'\n';
		}
		else if(_ == 11 || _ == 12)		//特殊性质 A 
		{
			int step = d / (a[2] - a[1]);
			if(step <= 1)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<max(0,n - 2 *  step + 1)<<'\n';
			}
		}
	}
	return 0;
}
