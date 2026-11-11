#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,ans=0;
char c;
string s;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			s+=c;
		}
	}
	int l=s.size();
	int mid=l/2;
	for(int i=0;i<mid;i++)
	{
		if(s[i]!=s[l-1-i]) ans++;
	}
	cout<<ans;
	return 0;
} 
