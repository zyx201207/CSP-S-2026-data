#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	long long n,l=0,m=0,a;
	string s;
	s="p";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		l+=a;
		for(int j=1;j<=a;j++)
		s+=c;
	}
	for(long long i=1;i<=(l+1)/2;i++)
	{
		if(s[i]!=s[l+1-i])
		m++;
	}
	cout<<m;
	return 0;
}
