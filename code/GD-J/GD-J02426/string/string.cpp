#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	int s1=a[1],s2=a[n];
	while(l<r)
	{
		if(s1>s2)
		{
			s1-=s2;
			if(c[l]!=c[r]) ans+=s2;
			s2=a[--r];
		}
		else
		{
			s2-=s1;
			if(c[l]!=c[r]) ans+=s1;
			s1=a[++l];
		}
	}
	cout<<ans;
	return 0;
}
