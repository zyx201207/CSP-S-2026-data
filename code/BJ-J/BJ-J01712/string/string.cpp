#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0,l=0,r=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
			r++;
		}
	}
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
