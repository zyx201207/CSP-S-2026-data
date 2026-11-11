#include<bits/stdc++.h> 
using namespace std;
char c[30];
int a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	string s;
	long long count=0,x=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cin>>c[i];
		x+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<x/2;i++)
	{
		int j=x-i+1;
		if(s[i]!=s[j])
		{
			count++;
		}
	}
	printf("%d",count);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
