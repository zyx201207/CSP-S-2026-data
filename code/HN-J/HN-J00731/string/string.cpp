#include<bits/stdc++.h>
using namespace std;
long long n,k,m,a[200010];
char b[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		while(a[i]--)
		{
			s=s+b[i];
		}
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	else if(n==2)
	{
		if(b[1]==b[2])
		{
			cout<<0;
		}
		else
		{
			cout<<min(a[1],a[2]);
		}
		return 0;
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			k++;
		}
	}
	cout<<k;
	return 0;
}

