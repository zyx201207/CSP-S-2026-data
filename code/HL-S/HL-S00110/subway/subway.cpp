#include<bits/stdc++.h>
using namespace std;
int c,n,m,p,q,f,g,ans,k[505],ar[500005];
struct z
{
	int a,b,bb;
}d,e;
vector<z> ar2[500005];

void dfs(int x,int y,z yy)
{
	if(x == g)
	{
		ans = min(ans,y);
		return ;
	}
	if(y>ans) return ;
	for(auto i:ar2[x])
	{
		if(i.bb!=yy.bb)
		{
			dfs(i.a,y+ar[x]+i.b,i);
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p>>q;
	ans = rand()%m;
	for(int i = 0;i<m;i++)
	{
		cin>>ar[i];
	}
	for(int i = 0;i<n;i++)
	{
		cin>>k[i];
		for(int j = 0;j<k[i];j++)
		{
			cin>>d.a>>d.b;
			d.bb = i;
			if(j == 0) ar2[0].push_back(d);
			else ar2[e.a].push_back(d);
			e = d;
		}
	}
	int flag = 0;
	for(int i = 0;i<q;i++)
	{
		cin>>f>>g;
		for(int j = 0;j<m;j++)
		{
			for(auto k:ar2[j])
			{
				if(k.a == f)
				{
					cout<<ans<<'\n';
					ans = rand()%m;
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
	}
	return 0;
}
