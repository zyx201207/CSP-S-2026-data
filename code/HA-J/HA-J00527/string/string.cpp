#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long a;
	char c;
}b[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&b[i].a,&b[i].c);
	}
	long long ret=0;
	for(int i=1;;)
	{
		int f=0;
		for(int j=n;j>i;)
		{
			if(b[i].c!=b[j].c)
			{
				ret+=min(b[i].a,b[j].a);
			}
			if(b[i].a>b[j].a)
			{
				b[i].a-=b[j].a;
				j--;
			}
			else
			{
				b[j].a-=b[i].a;
				i++;
			}
			if(j==i)
			{
				f=1;
			}
		}
		if(f==1)
		{
			break;
		}
	}
	printf("%lld",ret);
	return 0;
}
