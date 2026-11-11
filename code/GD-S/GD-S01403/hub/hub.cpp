#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
struct Point
{
	int dis = 0;
	int fa = 0;
	vector<int> son;
};
int main()
{
	//freopen("hub.in","r",stdin);
	freopen("hub1.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<Point> tree(n+1);
		for(int i = 1;i < n;++i)
		{
			int u,v;
			cin>>u>>v;
			if(u > v)swap(u,v);
			tree[u].son.push_back(v);
			tree[v].fa = u;
		}vector<bool> vis(n+1,0);
		
		while(cnt <= k)
	}
}
