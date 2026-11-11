#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long 
int a[100010];
char c[100010];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	map<int,char>mp;
	int b=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			b++;
			mp[b]=c[i];
		}
	}
	int sum=0;
	for(int i=1;i<=b/2;i++)
	{
		int j=b-i;
		if(mp[i]!=mp[j])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
