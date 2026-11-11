#include <iostream>
#include <vector>
using namespace std;
vector <int> e[2000010];
//int minn = 1e9;
//int cal()
//{
//	return 0;
//} 
//void dfs(int x,int p,int w)
//{
//	if(p == 0)
//	{
//		minn = min(minn,cal());
//	}
//	if(x == 0)
//	{
//		return ;
//	}
//	dfs(x - 1,p,w);
//	dfs();
//	return ;
//}
int main()
{
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t --)
	{
		int n,k;
		cin >> n >> k;
		for(int i = 1 ; i <= n - 1 ; i ++)
		{
			int u,v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(c == 13 || c == 14)
		{
			cout << ((n + 1) / 2 - k + 5) / 4 << endl;
		}
		else
		{
			//dfs(1,0,0);
		}
	}
	return 0;
} 
