#include <cstdio>
using namespace std;

int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	unsigned long long a[n+1],sum=0,sum1=0;
	char b[n+1],ch;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&ch);
		sum+=a[i];
		b[i]=ch;
	}
	for(int i=1;i<=n;i++)
	{
		if(sum1+a[i]>=sum/2)
		{
			sum1+=a[i];
			break;
		}
		sum1+=a[i];
	}
	if(sum % 2==0)
	{
		printf("%lld",sum-sum1);
	}
	else
	{	if(sum1==sum/2)
			printf("%lld",sum1);
		if(sum1>sum/2)
			printf("%lld",sum-sum1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
