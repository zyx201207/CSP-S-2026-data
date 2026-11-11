#include<bits/stdc++.h>
using namespace std;
long long a,ans=1;

string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a; 
	for(long long i=1;i<=a;i++)
	{
		long long b;
		string c;
		cin>>b>>c;
		for(long long j=ans;j<=b+ans;j++)
		{
			s[j]=c[0];
		}
		ans+=b;
	}
	long long sum=0,d;
	d=ans/2;
	for(long long i=1;i<=ans;i++)
	{
		
		if(s[i]==s[ans-i])
		{
			sum++;
		}
		
		
	}
	if(ans%2==0)
	{
		if(ans==sum)
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		if(sum==ans-1)
		{
			cout<<0;
			return 0;
		}
	}
	long long zui=0,buguan=0;
	for(long long i=1;i<=d;i++)
	{
			
		if(s[i]==s[ans-i])
		{
			buguan++;
		}
		else
		{
			zui++;
		}
	}
	cout<<zui;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
