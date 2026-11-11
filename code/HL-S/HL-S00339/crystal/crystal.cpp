#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long a[500050];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		long long cnt=m,sd=0;
		for(int j=n;j>=1;j--)
		{
			int s=a[i]-a[j];
			
			if(cnt>=s)
			{
				sd++;
				cnt-=abs(s);
				
			}
			else
			{
			  sum=max(sum,sd);
			  
			  break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
