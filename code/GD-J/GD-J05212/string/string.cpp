#include<bits/stdc++.h>
using namespace std;
long long n,a,len,flag=0,ans=0;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	len=s.size();
	for(long long i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
