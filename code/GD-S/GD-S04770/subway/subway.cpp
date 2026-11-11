#include <bits/stdc++.h>
using namespace std;

int a[500005];
map<int,int> mp[505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,o,x,y,t=1,mins=INT_MAX,l;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>o;
		for(int j=1;j<=o;j++)
		{
			cin>>x>>y;
			mp[t][x]=y;
		}
		t++;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		for(int i=1;i<t;i++)
		{
			if(mp[t][x]&&mp[t][x]<mins)
			{
				mins=mp[t][x];
				l=t;	
			}
		}
		if(mp[l][y]) 
		{
			cout<<a[x]+mp[t][x]+mp[t][y]+a[y];
			continue;
		} 
	}
}
