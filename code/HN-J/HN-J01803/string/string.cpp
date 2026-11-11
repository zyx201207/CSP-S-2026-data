#include<bits/stdc++.h>
using namespace std;
int a[100005];
char c[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		scanf("%s",&c[i]);
	}
	long long leng=0;
	for(int i=1;i<=n;i++)
	{
		leng+=a[i];
		if(c[i+1]==c[1])
		{
			a[1]+=a[i];
		}
	}
	long long leng2;
	if(a[1]==leng)
	{
		printf("0");
	}
	else
	{
		if(leng%2==0)
		{
			leng2=a[1];	
		}
		else
		{
			leng2=a[1]+1;
		}
		printf("%lld",leng-leng2);		
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
