#include<bits/stdc++.h>
using namespace std;
const long long cs=1ll>>60;
long long a[cs];
char c[cs],s[cs];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	if(n==1)
	{
		printf("0");
		return 0;
	}
	else if(n==2)
	{
		if(c[1]==c[2])
		{
			printf("0");
			return 0;
		}
		else
		{
			printf("%lld",min(a[1],a[2]));
			return 0;
		}
	}
	long long f=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s[f]=c[i];
//			printf("%c",s[f]);
			f++;
		}
	}
	long long l=1,r=f-1,cn=0;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cn++;
			l++;
			r--;
		}
		else
		{
			l++;
			r--;
		}
	}
	printf("%lld",cn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
