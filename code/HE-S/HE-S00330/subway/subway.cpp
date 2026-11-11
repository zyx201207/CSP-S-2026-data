#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long w[m+4],a[503][m+4],t[503][m+4],x[q+3],y[q+3];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int a1=0;a1<k;a1++)
		{
			cin>>a[i][a1]>>t[i][a1];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>x[i]>>y[i];
		cout<<w[i];
	}
	return 0;
}
