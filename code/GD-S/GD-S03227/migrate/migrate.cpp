#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	while(t--)
	{
		int cnt=0;
		cin>>n>>d;
		long long x[n],a[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=INT_MAX;
		for(int i=0;i<n;i++)cin>>x[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(x[i]-x[j]<=d&&x[j]-x[i]<=d)a[i][j]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=i+1;k<j;k++)
					if(a[i][k]+a[k][j]<a[i][j])a[i][j]=a[i][k]+a[k][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int tmp=0;
				for(int k=i+1;k<j;k++)
					if(a[i][k]+a[k][j]==a[i][j])tmp++;
				if(tmp==2)cnt++;
			}
		cout<<cnt<<endl;
	}
	return 0;
}
