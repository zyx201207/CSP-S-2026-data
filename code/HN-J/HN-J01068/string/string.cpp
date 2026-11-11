#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,ans=0;
char c[200005],s1,s2;
int main() 
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
	}
	long long stepr=0,stepl=n+1,syr=0,syl=0;
	for(;stepr<stepl;)
	{
		if(s1!=s2)
		{
			if(syr>=syl)
			{
				syr-=syl;
				ans+=syl;
				syl=0;
			}
			else{
				ans+=syr;
				syl-=syr;
				syr=0;
			}
		}
		else
		{
			if(syr>=syl)
			{
				syr-=syl;
				syl=0;
			}
			else{
				syl-=syr;
				syr=0;
			}
		}
		if(syr==0)
		{
			stepr++;
			syr=a[stepr];
			s1=c[stepr];
		}
		if(syl==0)
		{
			stepl--;
			syl=a[stepl];
			s2=c[stepl];
		}
	}
	cout<<ans;
	return 0;
}
