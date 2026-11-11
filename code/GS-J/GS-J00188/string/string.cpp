#include<bits/stdc++.h>
using namespace std;

string s,s2;
long long a=0,n=0;
char c='a';
long long num=0,ans=0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a>>c;
		for(long long i=0;i<a;i++)
		{
			s[num]=c;
			
			num++;
		}
	}
	long long j=num-1;
	for(long long i=0;i<num;i++)
	{
		
		
		s2[i]=s[j];
		
		j--;
	}
	
	for(long long i=0;i<num;i++)
	{
		if(s[i]!=s2[i])
		{
			
			ans++;
		}
	}
	
	
	cout<<ans/2;
	
	return 0;
}
