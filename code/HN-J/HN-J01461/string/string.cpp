#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	s="";
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>a[i]>>x;
		for(int j=1;j<=a[i];j++)
		{
			s+=x;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i])
		{
			ans++;
		}
	}
	if(s.size()%2==1)
	{
		ans--;
	}
	cout<<ans;
	return 0;	
} 
