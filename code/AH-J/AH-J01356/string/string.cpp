#include<bits/stdc++.h>
using namespace std;
struct Node
{
	long long a;
	char c;
	long long sum;
}st[200001];
long long n;
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld %c",&st[i].a,&st[i].c);
		st[i].sum=st[i-1].sum+st[i].a;
	}
	long long ans=0;
	if(st[n].sum<=200000)
	{
		long long k=0;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=st[i].a;j++)
				s[k++]=st[i].c;
		}
		long long len=st[n].sum;
		long long m=len/2;
		for(long long i=0;i<m;i++)
		{
			if(s[i]!=s[len-i-1])ans++;
		}
		printf("%lld",ans);
	}
	else
	{
		long long l=1,r=n;
		while(l<=r)
		{
			long long Num=min(st[l].a,st[r].a);
			if(st[l].c!=st[r].c)ans+=Num;
			if(Num==st[l].a)
			{
				l++;
				st[r].a-=Num;
			}
			else
			{
				r--;
				st[l].a-=Num;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
