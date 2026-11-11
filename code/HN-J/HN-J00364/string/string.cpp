#include<bits/stdc++.h>
using namespace std;
int a[200005];
char s[200005];
int n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		getchar();
		scanf("%c",&s[i]);
		getchar();
	}
	bool e=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[i+1])
		{
			e=1;
		}
	}
	if(e==0)
	{
		printf("0");
		return 0;
	}
	if(n==2)
	{
		if(s[1]==s[2])
		{
			
			printf("0");
			return 0;
		}
		if(a[1]==a[2])
		{
			printf("%d",a[1]);
			return 0;
		}
		if(a[1]>a[2])
		{
			printf("%d",a[2]);
			return 0;
		}
		if(a[1]<a[2])
		{
			printf("%d",a[1]);
			return 0;
		}
	}
	if(n==3&&a[1]==a[3]&&s[1]!=s[2]&&s[2]!=s[3]&&s[1]!=s[3])
	{
		printf("%d",a[1]);
		return 0;
	}
	if(n==3&&a[1]==a[3]&&s[1]==s[3])
	{
		printf("0");
		return 0;
	}
	if(n==3&&a[1]>a[3]&&s[1]==s[3])
	{
		if(a[2]>a[1]-a[3])
		{
			int x=a[1]-a[3];
			printf("%d",x);
		}
		else if(a[2]<a[1]-a[3])
		{
			printf("%d",a[2]);
		}
		return 0;
	}
	if(n==3&&a[1]<a[3]&&s[1]==s[3])
	{
		if(a[2]>a[3]-a[1])
		{
			int x=a[3]-a[1];
			printf("%d",x);
		}
		else if(a[2]<a[3]-a[1])
		{
			printf("%d",a[2]);
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
