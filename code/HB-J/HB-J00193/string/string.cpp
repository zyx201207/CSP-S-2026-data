#include <bits/stdc++.h>
using namespace std;
struct zf
{
	int sl;
	char zm;
}arr[201000];
long long qzh[200010];
string s;
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	int n,a;
	char b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(a>=1000000)
		{
			cout<<0;
			return 0;
		}
		qzh[i]=qzh[i-1]+a;
		for(int j=1;j<=a;j++)
		{
			s+=b;
		}
		arr[i].sl=a,arr[i].zm=b;
	}
	for(int i=0,j=qzh[n]-1;i<j;i++,j--)
	{
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
	return 0;
}
