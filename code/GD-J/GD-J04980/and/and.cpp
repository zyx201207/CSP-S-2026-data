#include<bits/stdc++.h>
using namespace std;
long long m=0,n=0;
long long dp[200005];
vector<long long> a(200005);
long long wand(long long a,long long b)
{
	int a2[31],b2[31];
	memset(a2,0,sizeof(a2));
	memset(b2,0,sizeof(b2));
	int lena=0,lenb=0;
	while(a>0)
	{
		a2[lena]=a%2;
		lena++;
		a=a/2;
	}
	while(b>0)
	{
		b2[lenb]=b%2;
		lenb++;
		b=b/2;
	}
	int maxx=max(lena,lenb);
	long long sum=0;
	for(int i=0;i<maxx;i++)
	{
		if(a2[i]&&b2[i])
		{
			sum=sum+(1ULL<<i); 
		}
	}
	return sum;
} 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[0]=2147483647;
	long long tmp=0,tmp2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			tmp=dp[i];
			dp[i]=max(dp[i],wand(dp[i-1],a[j]));
			if(tmp!=dp[i])
			{
				tmp2=j;
			}
		}
		a.erase(a.begin()+tmp2);
	}
	cout<<dp[m];
	return 0;
}
