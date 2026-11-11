#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int sa=1;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		if(a[i]!=1) sa=0;
	}
	if(sa==1)
	{
		int ans=0;
		for(int i=1,j=n;i<j;i++,j--)
		{
			if(c[i]!=c[j]) ans++;
		}
		cout << ans;
	}
	else
	{
		string s="";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=c[i];
			}
		}
		s=" "+s;
		int ans=0;
		for(int i=1,j=s.size()-1;i<j;i++,j--)
		{
			if(s[i]!=s[j]) ans++;
		}
		cout << ans;
	}
	return 0;
}
