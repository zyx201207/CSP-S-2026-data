#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long cnt;
char a;
int main()
{
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	long long n;
	cin>>n;
	long long m;
	int x=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>m;
		cin>>a;
		
		for(long long j=1;j<=m;j++)
		{
			s1[x]=a;
			x++;
		}
	}
	long long j=0;
	for(long long i=x-1;i>=0;i--)
    {
    	s2[j]=s1[i];
    	j++;
	}
	for(long long i=x-1;i>=0;i--)
	{
		if(s1[i]!=s2[i])cnt++;
	}
	cout<<cnt/2;
	return 0;
 } 
