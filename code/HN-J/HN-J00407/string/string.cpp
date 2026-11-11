#include <cstdio>
using namespace std;

char s[40000000010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n,a;
	long long count=0,num=1;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a,&c);
		for(int j=1;j<=a;j++)
		{
			s[num]=c;
			num++;
		}
	}
	num--;
	long long mid=(num+1)/2;
	for(long long i=0;i<mid;i++)
	{
		if(s[i+1]!=s[num-i])
			count++;
	}
	printf("%lld",count);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
