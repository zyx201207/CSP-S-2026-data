#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000066],ans;
long long book[2000006];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			long long h=x[j-1];
			book[j]=0;
			cin>>x[j];
			if(x[j]-h>d)
			{
				book[j]++;
				
			}
		}
		for(int q=1;q<=n;q++)
		{
			for(int s=q+1;s<=n;s++)
			{
				long long k=x[s]-x[q];
				
				if(k%d==d-1&&(k/d>0)&&book[s]==0&&book[q]==0)
				{
					ans++;
				}
			}
			
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
/*0 1
	6 2 -4 -3 -2 -1 3 6*/
