#include <bits/stdc++.h>
using namespace std;
string s,k,s1;
long long n,ans,x,l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x>>k;
		l+=x;
		for (int i=1;i<=x;i++)
			s+=k;
	}
	for (int i=l-1;i>=l/2;i--)
		s1+=s[i];
	for (int i=0;i<=s1.length()-1;i++)
	{
		if (s[i]!=s1[i])
			ans++;
	}
	cout<<ans;
	return 0;
} 	

