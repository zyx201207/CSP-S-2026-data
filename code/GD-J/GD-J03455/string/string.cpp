#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;cin>>x;
		char c;cin>>c;
		for(int j=1;j<=x;j++)
		{
			s+=c;
		}
	}
	long long num=0;
	long long len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			s[i]=s[len-1-i];
			num++;
		}
	}
	cout<<num;
	return 0;
}
