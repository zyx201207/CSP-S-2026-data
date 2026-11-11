#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
string s;
int n;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int ans=0;
	int len=s.size();
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
