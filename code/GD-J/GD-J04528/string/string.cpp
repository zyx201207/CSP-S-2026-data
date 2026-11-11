#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,ans=0,len;
char c;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		len+=a;
		for(int i=1;i<=a;i++)s.push_back(c);
	}
	if(len%2==1)len--;
	for(int i=0;i<len/2;i++)
	{
		if(s[i]!=s[len-i]){ans++;}
	}
	cout<<ans;
} 
