#include<bits/stdc++.h>
using namespace std;
long long a,b[100005];
char c;
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n,m,i,j=0,k;
	long long sum=0,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(j=1;j<=a;j++)
		{
			b[j]=c;
		}
		k+=a;
	}
	k=k/2;
	if(k%2==0)
	{
		j=1;
	}
	if(j==1)
	{
		for(i=k+1;i<=n;i++)
		{
			if(b[i]!=b[n-1])
			{
				sum++;
			}
		}
	}
	if(j==0)
	{
		for(i=k+2;i<=n;i++)
		{
			if(b[i]!=b[n-i+1])
			{
				sum++;
			}
		}
	}
	printf("%lld",sum);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
