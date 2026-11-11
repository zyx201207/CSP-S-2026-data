#include<bits/stdc++.h>
using namespace std;
const long long N=200010;
long long n,m,ans,a[N],can[N],s[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(can,-1,sizeof(can));
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=30;i>=0;i--)
	{
		memset(s,0,sizeof(s));
		int sl=0;
		for(int j=1;j<=n;j++)
		{
			if(can[j]&&(a[j]&(1<<i))) s[j]=1,sl++;
		}
		if(sl>=m)
		{
			ans+=(1<<i);
			for(int j=1;j<=n;j++) can[j]=s[j]; 
		}
	}
	cout<<ans;
	return 0;
}
