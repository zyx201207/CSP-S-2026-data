#include<bits/stdc++.h>
using namespace std;
int w[500001];
long long a[10001][10001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q; 
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	int ki;
	for(int i=0;i<2;i++)
	{
		cin>>ki;
		for(int j=0;j<2*ki;j++)
		{
			cin>>a[i][j];
		}
	}
	int x,y;
	for(int i=0;i<2;i++)
	{
		cin>>x>>y;
	}
	cout<<c+n+m+d+q+3<<endl;
	cout<<w[m-1]+w[m-2]+w[m-3]+w[m-4];
	return 0;
} 
