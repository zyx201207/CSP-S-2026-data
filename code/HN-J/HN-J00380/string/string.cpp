#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long n;
	long long cd=0,sc=0,sum=0,d=0;
	char s[200005],ts;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>cd;
		sc+=cd;
		cin>>ts;
		for(long long j=1;j<=cd;j++)
		{
			s[d++]=ts;
		}
	}
	char s1[200005],s2[200005];
	for(long long i=0;i<sc/2;i++)
	{
		s1[i]=s[i];
		s2[i]=s[sc-i-1];
	}
	if(s1==s2)
	{
		cout<<"0";
	}
	else
	{
		for(long long i=0;i<sc/2;i++)
		{
			if(s1[i]!=s2[i])
			{
				sum++;
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
