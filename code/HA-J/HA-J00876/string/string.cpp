#include<bits/stdc++.h>
using namespace std;
long long k,n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s="";
	string s1;
	for(long long i=1;i<=n;i++)
	{
		cin>>k>>s1;
		for(int j=1;j<=k;j++)
		s+=s1;
	}

	long long len=s.size();
	if(len%2!=0)
	len++;
	long long len1=s.size();
	for(long long i=0;i<len/2;i++)
	{ 
		if(s[i]!=s[len1-i-1])
		ans++;
	}
	cout<<ans;
	return 0;
}
