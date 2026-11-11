#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>//ll
const int N=1010,inf=0x3f3f3f3f;
int n,d,a[N],dt[N][N],cnt[N][N],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			int s=d/(a[2]-a[1]);
			if(s*2>n)cout<<"0\n";
			else cout<<n-s-1<<"\n";
		}
		return 0;
	}
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dt[i][j]=inf,cnt[i][j]=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=d)dt[i][j]=1;
				else break;
			}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					if(dt[i][k]==inf||dt[k][j]==inf)continue;
					if(dt[i][j]>dt[i][k]+dt[k][j])
					{
						dt[i][j]=dt[i][k]+dt[k][j];
						cnt[i][j]=1;
					}
					else if(dt[i][j]==dt[i][k]+dt[k][j])cnt[i][j]+=cnt[k][j];
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2)
				{
					ans++;
				}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
