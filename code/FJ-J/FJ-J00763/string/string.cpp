#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin>>n; 
	long long a;
	char ch;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>ch;
		m+=a;
	    for(int j=1;j<=a;j++)
	    {
	    	s+=ch;
		}
	}  
	long long ans=0; 
	for(int i=0;i<m/2;i++)
	{
		if(s[i]!=s[m-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
} 
