#include<iostream>
#define ll long long
using namespace std;
const int N=2e6+5;
ll a[N],d;
int t[N],dp[N],n,q,c,sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			dp[i]=N;
			t[i]=0;
		}
		sum=0;
		dp[1]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]>d) break;
				if(dp[j]>dp[i]+1)
				{
					dp[j]=dp[i]+1;
					t[j]=1;
				}
				else
				{
					if(dp[j]==dp[i]+1) t[j]++;
				}
			}
		} 
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(t[j]-t[i]==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
