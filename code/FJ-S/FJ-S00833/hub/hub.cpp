#include<bits/stdc++.h>
using namespace std;
int b[50005],k,t,n,m,f=INT_MAX,g;
struct jgt
{
	int x,y,z;
};
vector<int>a[50005];
void pd(int x,int y)
{
	for(int s:a[x])
	{
		if(s!=y)
		{
			if(b[s]==1&&b[x]==0)g++;
			pd(s,x);
		}
	}
}
void dfs(int x,int y)
{
	if(y==m)
	{
		g=0;
		pd(1,0);
		if(g>2)return;
		int l=0;
		for(int s=1;s<=n;s++)
		{
			int h=0;
			if(!b[s])
			{
				queue<jgt>q;
				q.push({s,0,0});
				while(!q.empty())
				{
					jgt t=q.front();
					q.pop();
					for(int d:a[t.x])
					{
						if(d!=t.y)
						{
							if(b[d]){h=t.z+1;break;}
							q.push({d,t.x,t.z+1});
						}
					}
					if(h)break;
				}
				l=max(l,h);	
			}
		}
		f=min(f,l);
		return;
	}
	if(x==n)return;
	for(int s=x+1;s<=n-(m-y)+1;s++)
	{
		b[s]=1;
		dfs(s,y+1);
		b[s]=0;
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","r",stdout);
	cin>>k;
	if(1)
	{
		cin>>t;
		while(t--)
		{
			f=INT_MAX;
			cin>>n>>m;
			for(int s=1;s<=n;s++)a[s].clear();
			for(int s=1;s<n;s++)
			{
				int x,y;
				cin>>x>>y;
				a[x].push_back(y);
				a[y].push_back(x);
			}
			dfs(0,0);
			cout<<f<<endl;
		}
	}
	return 0;
}
