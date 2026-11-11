#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin>>n;
	char c;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long si=s.size()-1;
	long long sum=0;
	for(int i=si;i>=si/2;i--)
	{
		if(s[si-i]!=s[i])
		{
			s[i]=s[si-1];
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
