#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define rd "%d"

namespace marlin
{
	constexpr int N=5e5+5;
	constexpr int M=3e5+5;
	int n,m;
	stack<int> exists[M];
	struct range
	{
		int l=0,r=0;
		range(int l_=0,int r_=0)
		{
			l=l_;r=r_;
		}
	};
	int res[M];
	int d[N];
	int las[N];
	bitset<N> ever;
	int next[N];
	bool try_connect(range a, range b, range& out)
	{
		if (b.l<a.l) return try_connect(b,a,out);
		if (b.l<=a.r)
		{
			out=range(a.l,max(a.r,b.r));
			return true;
		}
		return false;
	}
	int get_length(const vector<range>& v)
	{
		int l=0;
		for (register range j : v)
		l+=j.r-j.l;
		return l;
	}
	void append_range(vector<range>& v, range r)
	{
		if (r.r-r.l==0) return;
		WHENDEBUG printf("rl. %d -> ",get_length(v));
		for (register int i=0;i<v.size();i++)
		{
			auto& item=v[i];
			if (try_connect(item,r,item))
			{
				for (register int j=i+1;j<v.size();j++)
				{
					if (try_connect(item,v[j],item))
					{
						v[j].l=v[j].r=0;
					}
				}
				WHENDEBUG printf("%d\n",get_length(v));
				return;
			}
		}
		v.push_back(r);
		WHENDEBUG printf("%d\n",get_length(v));
	}
	bool solve(int s, bitset<M>& exist, bool add=true)
	{
		if (s>n) return false;
		if (ever[s]) return false;
		ever[s]=true;
		WHENDEBUG printf("s. %d\n",s);
		bitset<M> my; 
		for (register int i=s;i<=n;i++)
		{
			my[d[i]]=true;
			if (!exist[d[i]]&&!add)
			{
				res[d[i]]++;
			 } 
			 exist[d[i]] = true;
			if (next[i])
			{
				solve(next[i]+1,my);
				break;
			}
			else
			{
				WHENDEBUG printf("exist t %d\n",d[i]);
			}
		}
		WHENDEBUG printf("a ");
		for (register int i=1;i<=m;i++)
		{
			if (my[i]) res[i]++;
			WHENDEBUG printf("%d ",res[i]);
		}
		WHENDEBUG printf("\n ");
		return true;
	}
	void main()
	{
		scanf(rd rd,&n,&m);
		memset(las,0,sizeof(las));
		for (register int i=1;i<=n;i++)
		{
			scanf(rd,d+i);
			if (las[d[i]])
			next[las[d[i]]]=i;
			las[d[i]]=i;
		}
		for (register int i=1;i<=n;i++)
		{
			bitset<M> exist;
			solve(i,exist);
		}
		for (register int i=1;i<=m;i++)
		{
			printf(rd " ",res[i]);
		}
	}
}

signed main()
{
	WHENDEBUG freopen("card2.in","r",stdin);
	WHENDEBUG{}else freopen("card.in","r",stdin);
	WHENDEBUG{}else freopen("card.out","w",stdout);
	marlin::main();
	return 0; 
}
