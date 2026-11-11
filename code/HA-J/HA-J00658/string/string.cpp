#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0;
const int maxn=2e5+5;
vector<char>s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		sum+=a;
		while(a)
		{
			s.push_back(c);
			a--;
		}
	}
	int ans=0;
	sum--;
	for(int i=0;i<s.size();i++)
	{
		if(i==sum-i)break;
		if(s[i]!=s[sum-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
