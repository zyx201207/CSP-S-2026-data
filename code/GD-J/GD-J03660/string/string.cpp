#include<bits/stdc++.h>
using namespace std;

char c[500010],tmp1,tmp2;
long long n,a[500010],sum1,sum2,l,r,index1,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		scanf(" %c",&c[i]);
	}
	l=1,r=n;
	sum1=a[1],sum2=a[n];
	tmp1=c[1],tmp2=c[n];
	if(sum1>=sum2)
	{
		if(tmp1!=tmp2)	ans+=sum2;
		sum1-=sum2;
		sum2=0;
	}
	else
	{
		if(tmp1!=tmp2)	ans+=sum1;
		sum2-=sum1;
		sum1=0;
	}
	while(1)
	{
		index1=0;
		if(sum2==0)
		{
			for(int i=r-1;i>=l+1;i--)
			{
				index1=i;
				sum2=a[i];
				tmp2=c[i];
				if(sum1<sum2)	break;
				if(c[i]!=tmp1)	ans+=a[i];
				sum1-=sum2;
			}
			if(sum1>=sum2)	break;
			if(tmp1!=tmp2)	ans+=sum1;
			sum1=0;
			r=index1;
		}
		else
		{
			for(int i=l+1;i<=r-1;i++)
			{
				index1=i;
				sum1=a[i];
				tmp1=c[i];
				if(sum2<sum1)	break;
				if(c[i]!=tmp2)	ans+=sum1;
				sum2-=sum1;
			}
			if(sum2>=sum1)	break;
			if(tmp1!=tmp2)	ans+=sum2;
			sum2=0;
			l=index1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/
