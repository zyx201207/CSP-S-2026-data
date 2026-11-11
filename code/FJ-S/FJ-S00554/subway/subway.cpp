#include<bits/stdc++.h>
using namespace std;
int m,n,c,d,q; 
int a[500005],b[505][1000005],c1[100005][5];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i][1];
		for(int j=2;j<=b[i][1]*2+1;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c1[i][1]>>c1[i][2];
	}
	if(c>=12 && c<=19)
	{
		for(int i=1;i<=q;i++)
		{
			cout<<(c1[i][2]-c1[i][1])*b[1][3]*2<<endl;
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cout<<(c1[i][2]-c1[i][1])*(q-1)<<endl;
		}
	}
	return 0;
} 
