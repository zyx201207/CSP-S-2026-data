#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,a;
	char c;
	string x="";
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		sum+=a;
		while(a>0)
		{
			s+=c;
			a--;
		}
	}
	long long ans=0;
	sum--;
	if(s.size()%2==1)
	{
	for(int i=0;i<(s.size()-1)/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			ans++;
		}
	}
	cout<<ans;s
	return 0;
   }
   else
   {
   	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[sum-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0; 
   }
}
