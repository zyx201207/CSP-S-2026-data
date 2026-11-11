#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N],b[N];
long long n,d,r1[5000][5000];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int ans=0,cnt=0;
		
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			a[i]+=1e18;
		}
		a[n+1]=a[n]+d;
		for(int i=1;i<=n;i++)
		{
			int nw=i,j=i+1,sum=1;
			while(j<=n+1)
			{
				if(a[j]-a[nw]>d)
				{
					nw=j-1;
					sum++;
				}
				r1[i][j]=sum;
				j++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				long long a=2e18,cnt=0;
				for(int k=i+1;k<j;k++)
				{
					a=min(a,r1[i][k]+r1[k+1][j]);
				}
				for(int k=i+1;k<j;k++)
				{
					if(r1[i][k]+r1[k+1][j]==a)
					{
						cnt++;
					}
				}
				if(cnt==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
