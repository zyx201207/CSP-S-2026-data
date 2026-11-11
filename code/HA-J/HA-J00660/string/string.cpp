#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long ai;
	char c;
	string s;
	int f=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ai>>c;
		while(ai!=0)
		{
			s[f++]=c;
			ai--;
		}
	}
	int ans=0;
	string s1;
	int l=f-1;
	for(int i=0;i<f;i++)
	{
		s1[i]=s[l];
		l--;
	}
		for(int i=0;i<f;i++)
	{
		if(s1[i]!=s[i])
		ans++;
	}
	cout<<ans;
	return 0;
}
