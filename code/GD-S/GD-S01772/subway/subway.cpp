#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
int c,n,m,d,q;
int w[N];
int k[N];
vector<vector<int> > a,t;
int x,y; 
int main()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	while(q--)
	{
		
	}
}
