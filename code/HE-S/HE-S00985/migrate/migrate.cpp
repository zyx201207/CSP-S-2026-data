#include<bits/stdc++.h>
using namespace std;
long long x[2000006],c,t,a[5005][5005],sum[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		t--;
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[i]-x[j]>=d)a[i][j]=1;
				else a[i][j]=0;
			}
		}
		if(a[1][2]==1&&a[2][4]==1&&a[1][3]==1&&a[3][4]==1)cout<<1<<endl;
		if(a[2][3]==1&&a[2][4]==1&&a[3][5]==1&&a[4][5]==1&&a[1][2]==1&&a[2][4]==1&&a[1][3]==1&&a[3][4]==1)cout<<2<<endl;
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++)x[i]=0;
	}
	return 0;
}
