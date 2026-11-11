#include <bits/stdc++.h>
using namespace std;

long long n,a,ans;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	if(n==1)
	{
		cout <<"0";
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		cin >>a >>c;
		for(long long j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++)
	{
		if(s[i]!=s[n-i+1])
		{
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
























































//AC!
