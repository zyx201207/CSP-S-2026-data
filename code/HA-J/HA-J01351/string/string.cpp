#include<bits/stdc++.h>
using namespace std;

long long n,len,ans=0;
const int maxn=2e5+5;
long long a[maxn];
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	bool sum=true;
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1]) sum=false;
	}
	if(sum==true)
	{
		cout<<0;
		return 0;
	}
	len=s.size();
	long long d=len;
	if(len%2==0)
	{
		len/=2;
	}
	else
	{
		len+=1;
		len/=2;
	}
	for(int i=1;i<=len;i++)
	{
		if(s[i]!=s[d-i+1])ans++;
	}
	cout<<ans;
	
	return 0;
}
