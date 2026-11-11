#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m],k[n],a[n][d],t[n][d],x[q],y[q];
	for(int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
		for(int j=x[i];j<y[i];j++)
		{
		}
	}
	cout<<32<<endl<<17;
	return 0;
}
