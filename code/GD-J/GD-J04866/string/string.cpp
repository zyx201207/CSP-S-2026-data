#include <bits/stdc++.h>
using namespace std;
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		int x;
		string a;
		cin>>x;
		cin>>a;
		while(x--) s+=a;
	}
	for(int i = 0;i<s.size()/2;i++)
	{
		if(s[i]==s[s.size()-i-1])
		{
			continue;
		}
		if(s[i]!=s[s.size()-i]) 
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
