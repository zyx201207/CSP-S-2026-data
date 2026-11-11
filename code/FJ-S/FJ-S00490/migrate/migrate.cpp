#include<bits/stdc++.h>
using namespace std;
long long  c,t,ans,n,d,a[2000005],sum[2000005],ss[2000005],l,s[2000005],dp[2000005],q[2000005],head,tail;
int main()
{
	

		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t)
	{
		t--;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			ss[i]=0;
			cin>>a[i];
		 
		}
		if(n>=1e5){
			long long o=d/(a[n]-a[n-1]);
		ans=0;
		for(int i=o+1;i<=n;i++)
		{
			if(i-o>=o)
			{
				ans+=o-1;
			}
			else
			{
				ans+=i-o;
			}
		}
		cout<<ans<<"\n";
		continue;
		}
		l=n;
		
		for(int j=n;j>=1;j--)
		{
			while(l-1>=1&&a[j]-a[l-1]<=d)
			{
				l--;
			}	
			s[j]=l;
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			head=tail=i;
			q[1]=i;
			dp[i]=0;
			ss[i]=1;
			long long sum=1;
			for(int j=i+1;j<=n;j++)
			{
				if(s[j]==j)
				{
					break;
				}
				while(head<s[j])
				{
					
					sum-=ss[head];
					head++;
					if(tail<head){
					
					tail++;
					sum+=ss[tail];
					while(dp[tail+1]==dp[tail])
					{
						tail++;
						sum+=ss[tail];
					}
					}
					
				}
				if(tail>=head)
				{
					dp[j]=dp[head]+1;
					ss[j]=sum;
					if(ss[j]==2)
					{
						ans++;
					}
				}
				
			}
			
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
