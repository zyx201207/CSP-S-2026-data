#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int c,t,n,d;
int x[N],dv[N],dw[N],dt[N];
 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=25)
	{
		while(t--)
		{
			cin>>n>>d;
			int flag=1;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				dv[i]=0;
			}
			for(int i=1;i<=n-2;i++)
			{
				if(x[i+1]-x[i]<=d && x[i+2]-x[i]>d) dv[i]=1; 
				else if(x[i+1]-x[i]>d) dv[i]=0;
				else 
				{
					int kk=upper_bound(x+i,x+n+1,x[i]+d)-x;
					dv[i]=kk-i+1;
				}
			}
			dv[n-1]=(x[n]-x[n-1]<=d ? 1 : 0);
			int sum=0,ans=0;
			for(int i=1;i<n;i++)
			{
				if(dv[i]%2==1)
				{
					sum++;
				}
				else if(dv[i]==0)
				{
					sum=0;
				}
				else 
				{
					ans+=sum;
					sum=1;
				}
		//		cout<<i<<" "<<sum<<" "<<ans<<endl; 
			}
		//	ans+=sum;
		//	sum=0;/*
			for(int i=n-1;i>=1;i--)
			{
				if(dv[i]==1)
				{
					sum++;
				}
				else if(dv[i]==0)
				{
					sum=0;
				}
				else if(dv[i]==2)
				{
					ans+=sum;
					cout<<i<<" "<<ans<<endl;
					sum=0;
				}
				cout<<i<<" "<<sum<<" "<<ans<<endl; 
			}
			cout<<ans<<endl;
		}
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
