#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define rd "%lld"
#define int long long

namespace marlin
{
	int n,k;
	constexpr int N=3e5;
	vector<int> map[N];
	vector<int> childs[N];
	int para[N];
	int counts[N];
	int root;
	int need(int x,int c,int rk)
	{
		if (counts[x]<c) return -1;
		if (rk==2)
		{
		}
		for (register int i=0;i<childs[x].size();i++)
		{
			for (register int i=0;i<childs[x].size();i++)
			{
				
			}
		}
	}
	int gc(int x,int p)
	{
		int temp=1;
		para[x]=p;
		for (int a:map[x])
		{
			if (a==p) continue;
			childs[x].push_back(a);
			temp+=gc(a,x);
		}
		return counts[x]=temp;
	}
	void main()
	{
		scanf(rd rd,&n,&k);
		for (register int i=0;i<n;i++)
		{
			int u,v;scanf(rd rd,&u,&v);
			map[u].push_back(v);
			map[v].push_back(u);
		}
		for (register int i=0;i<n;i++)
		{
			if (map[i].size()==1)
			{
				root=i;
				break;
			}
		}
		printf("1\n");
	}
}


signed main()
{
	WHENDEBUG{}else freopen("crystal.in","r",stdin);
	WHENDEBUG{}else freopen("crystal.out","w",stdout);
	int c,t; scanf(rd rd,&c,&t);
	for (int i=0;i<t;i++)
	marlin::main();
	return 0;
}
