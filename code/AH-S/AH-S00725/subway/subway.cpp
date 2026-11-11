#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q,m,n,mi[500000],ni[500][500000];
	cin>>c>>d>>n>>m>>q;
	for(int i=0;i<m;i++)
		cin>>mi[i];
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int a;
			cin>>a;
			cin>>ni[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		int t=mi[x]+mi[y];
		queue<pair<int,pair<int,int>>>v;
		v.push({x,0,0});
		while(!v.front.first==y)
		{
			for(int j=0;j<n;j++)
				v.push({v.front.second.first,{v.front.second.first+10,10}});
		}
		cout<<v.front.second.first+t;
	}
	return 0;
}
