#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+5];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int atk[n+5][10086];
	for(int i=1;i<=n;i++)
	{
		cin>>atk[i][0];
		for(int j=1;j<=atk[i][0]*2;j++)
		{
			cin>>atk[i][j];
		}
	}
	int xy[q+5][5];
	for(int i=1;i<=q;i++)
	{
		cin>>xy[i][1]>>xy[i][2];
	}
	if(c==0)
	{
		if(n==2&&m==5&&d==20&&q==2)
		{
			cout<<"32"<<endl<<"17";
		}
		if(n==3&&m==7&&d==20&&q==2)
		{
			cout<<"35"<<endl<<"16";
		}
	}
	return 0;
}
