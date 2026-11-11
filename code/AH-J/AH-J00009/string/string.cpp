#include<bits/stdc++.h>
using namespace std;
long long s[200010];
long long s1[200010];
char z[200010];
long long  sum,ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&s[i]);
		sum+=s[i];
		s1[i]=s1[i-1]+s[i];
		cin>>z[i];
	}
	long long g=0;
	for(int i=1,j=n;i<=n;i+=0)
	{
		if(i>j)break;
		if(i==j)
		{	
			break;
		}
		if(z[i]!=z[j])
		{
			ans+=min(s[i],min(s[j],sum/2-g));
		}
		long long p=min(s[i],min(s[j],sum/2-g));
		s[i]-=p;
		s[j]-=p;
		g+=p;
		if(s[i]==0)i++;
		if(s[j]==0)j--;
	}
	cout<<ans;
	return 0;
}
