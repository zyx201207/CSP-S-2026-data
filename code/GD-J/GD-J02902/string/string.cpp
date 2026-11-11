#include<bits/stdc++.h>
using namespace std;
string s=" ";
int n;
long long ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a; cin>>a;
		char c; cin>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	for(int i=1;i<=s.size()/2;i++)
	{
		if(s[i] != s[s.size()-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}

