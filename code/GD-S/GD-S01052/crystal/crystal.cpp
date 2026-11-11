#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int a[N];
int maxx,minn;
int n,m;
int ans=INT_MIN;
int zip(int x)
{
	int cnt=0;
	for(int i=n;i>=1;i--)
	{
		if(m<a[n]-a[i]) break;
		m-=a[n]-a[i];
		cnt++;
	}
	return cnt;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000)
	{
		int flag=0;
		int x=a[2]-a[1];
		for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=x) flag=1; 
		if(!flag)
		{
			cout<<zip(x);
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		int cnt=0;
		int res=m;
		for(int j=i;j>=1;j--)
		{
			if(res>=a[i]-a[j]) cnt++,res-=(a[i]-a[j]);
		}
		ans=max(cnt,ans);
	}
	cout<<ans;
} 
