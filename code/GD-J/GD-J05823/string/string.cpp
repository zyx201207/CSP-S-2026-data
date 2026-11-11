#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			s=s+a;
		}
	}
	string s1;
	s1=s;
	long long ans=0;
	reverse(s.begin(),s.end());
	int l=s.size()/2;
	for(int i=0;i<=l-1;i++)
	{
		if(s1[i]!=s[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

