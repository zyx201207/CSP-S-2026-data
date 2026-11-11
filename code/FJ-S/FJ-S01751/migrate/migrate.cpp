# include <bits/stdc++.h>
using namespace std;
const int N=5050;
const long long inf=3e18;
int n,c,t;
long long a[N],d;
long long Floyd[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				Floyd[i][j]=inf;
		
		int l=1,r=1,ans=0;
		for(int i=1;i<=n;i++)
		{
			while(a[i]-a[l]>d)++l;
			while(r<=n&&a[r]-a[i]<=d)++r;
			
			for(int j=l;j<r;j++)
				Floyd[i][j]=1;
			
			Floyd[i][i]=0;
		}
		
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(i!=j)
				{
					long long same=0,Min=inf;
					for(int k=i+1;k<j;k++)
					{
						int val=Floyd[i][k]+Floyd[k][j];
						if(val<Min)
							Min=val,same=1;
						else if(val==Min)
							++same;
					}
					if(Min<Floyd[i][j] && same==2)
						++ans;
					Floyd[i][j]=min(Floyd[i][j],Min);
				}
		cout<<ans<<"\n";
	}
}