#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int w[m+5],k[n+2],x[q+2],y[q+2],a[m+5],t[m+5];
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>a[i]>>t[i];
	}
	cout<<w[0]+t[0];
	
	
	return 0;
}
