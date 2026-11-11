#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[5001],y[5001][5001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		long long cnt,ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		memset(y,0x3f,sizeof(y));
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]<=d)y[i][j]=0;
				cnt=0;
				for(int k=i+1;k<j;k++)
				{
					if(x[j]-x[k]<=d)
					{
					if(y[i][j]==y[i][k]+1)cnt++;
					else if(y[i][j]>y[i][k]+1)cnt=1;
					y[i][j]=min(y[i][j],y[i][k]+1);}
				}
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//buhuiQWQ
//ljl
