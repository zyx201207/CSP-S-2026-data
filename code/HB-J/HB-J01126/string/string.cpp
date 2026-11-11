#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char b[200005];
char s1[10000010],s2[10000010];
int sum;
int main()
{
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int j0=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		for(int j=j0;j<=a[i]+j0-1;j++)
		{
			s1[j]=b[i];
		}
		j0=j0+a[i];
	}
	
	for(int i=0;i<j0;i++)
	{
		s2[i]=s1[j0-1-i];
	}
	for(int i=0;i<j0;i++)
	{
		if(s1[i]!=s2[i])
		{
			sum++;
			s2[i]=s1[i];
			s1[j0-1-i]=s1[i];
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
