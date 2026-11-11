#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,a,ans=0;
	char c;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a;
		cin>>c;
		for (int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int l=0,r=s.size()-1;
	while (l<=r)
	{
		if (s[l]!=s[r])  ans++;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
