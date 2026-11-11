#include<bits/stdc++.h>
using namespace std;

long long w[500010],a[10010][10010];

int main()
{
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>w[i];
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
			cin>>a[i][j];
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
	}
}
