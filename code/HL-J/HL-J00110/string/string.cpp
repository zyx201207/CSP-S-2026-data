#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	unsigned long long lenth;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		string s1;
		cin>>a>>s1;
		while(a)
		{
			s+=s1;
			a--;
		}
	}
	unsigned long long ans=0;
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}

