#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
struct aaa{
	int x;
	char y;
}a[200010];
string b[10];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	
	if(n<=1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].x;j++)
		{
			b[i]=b[i]+a[i].y;
		}
	}
	
	string s="";
	for(int i=1;i<=n;i++)
	{
		s+=b[i];
	}
	
	int cnt=0;
	int l=0;
	int r=s.size()-1;
	while(l<r)
	{
		if(l==(s.size()-1)/2) break;
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	cout<<cnt;
}
