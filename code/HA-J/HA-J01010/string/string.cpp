#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int l=s.size()-1,ans=0;
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
