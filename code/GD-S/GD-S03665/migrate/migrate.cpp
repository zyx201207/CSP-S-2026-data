#include <bits/stdc++.h>
using namespace std;

constexpr bool DEBUG=false;
#define WHENDEBUG if(DEBUG)
#define rd "%lld"
#define int long long

namespace marlin
{
	struct lower_t
	{
		int v=0,c=0;
		int hash=0;
		lower_t()
		{
			reset();
		}
		void reset()
		{
			v=LLONG_MAX;c=0;hash=0;
		}
		int more(int x,int h)
		{
			if (x<v)
			{
				v=x;c=1;
				hash=h;
				return 0;
			}
			if (x==v&&h!=hash)
			{
				c++;
				hash=h;
				return 1;
			}
			return 2;
		}
	};
	struct node
	{
		int v;int hash;
		node(int v_,int hash_)
		{
			v=v_;hash=hash_;
		}
	};
	constexpr int N=2e6+5;
	int n,dx;
	int d[N];
	int c;
	bitset<N> ever;
	lower_t dis[N];
	int solve(int w)
	{
		int temp=0;
		ever[w]=true;
		queue<node> ue;ue.push(node(w,w+1));
		dis[w].v=0;
		while (ue.size())
		{
			node fr=ue.front();ue.pop();
			int x=fr.v;
			int h=fr.hash;
			for (int i=x+1;i<n&&d[i]-d[x]<=dx;i++)
			{
				//WHENDEBUG printf("dis[i]. " rd " c " rd "\n",dis[i].v,dis[i].c);
				int ndis=dis[x].v+1;
				int qwq=dis[i].c==2;
				int wer=dis[i].more(ndis,h*(i+1));
				int must=false;
				WHENDEBUG printf("ndis. " rd " i " rd,ndis,i);
				if (wer!=2)
				{
					if (qwq&&dis[i].c!=2)
					{
						temp--;
						WHENDEBUG printf(" temp--");
					}
					if (dis[i].c==2)
					{
						temp++;
						must=true;
						WHENDEBUG printf(" temp++");
					}
				}
				WHENDEBUG printf("\n");
				if (wer==0||wer==1)
				{
					if (!ever[i]||must)
					{
						ever[i]=true;
						ue.push(node(i,h*(i+1)));
					}
				}
			}
		}
		return temp;
	}
	void main(int c_)
	{
		c=c_;
		scanf(rd rd,&n,&dx);
		for (register int i=0;i<n;i++)
		{
			scanf(rd,d+i);
		}
		int ans=0;
		for (register int i=0;i<n;i++)
		{
			ever.reset();
			for (register int j=i;j<n&&(j==i||d[j]-d[j-1]<=dx);j++)
			{
				dis[j].reset();
			}
			WHENDEBUG printf("\n");
			ans+=solve(i);
		}
		printf(rd "\n",ans);
	}
}


signed main()
{
	WHENDEBUG freopen("migrate1.in","r",stdin);
	WHENDEBUG{}else freopen("migrate.in","r",stdin);
	WHENDEBUG{}else freopen("migrate.out","w",stdout);
	int c,t; scanf(rd rd,&c,&t);
	for (int i=0;i<t;i++)
	marlin::main(c);
	return 0;
}
