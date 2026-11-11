#include<bits/stdc++.h>
using namespace std;
long long x[2000006],c,t,a[5005][5005],v[2000006],u[2000006],d;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,(2000006));
		int n;
		long long k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[i]-x[j]>=d)a[i][j]=1;
				else a[i][j]=0;
			}
		}
	}
	return 0;
}
