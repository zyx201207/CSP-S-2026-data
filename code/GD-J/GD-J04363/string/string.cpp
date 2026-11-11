#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,lol=0,sum=0;
char c;
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> c;
		for(int i=1;i<=x;i++)
		{
			s+=c;
		}
		lol+=x;
	}
	int l=0,r=lol-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			sum++;
			s[l]=s[r];
		}
		l++;
		r--;
	}
	cout << sum;
	return 0;
} 
