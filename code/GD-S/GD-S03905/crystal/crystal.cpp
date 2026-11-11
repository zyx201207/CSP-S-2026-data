#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
int dp[N];
int maxx=0;
int ans,cnt;
int sum;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort (a+1,a+n+1);
	sum=a[2]-a[1];
	int flag=1;
	for (int i=2;i<=n;i++)
	{
		if (a[i]-a[i-1]!=sum)
		{
			flag=0;
			break;
		}
	}
	if (flag)
	{
		int x=m/sum;
		int num=0;
		for (int i=1;;i++)
		{
			if (num+i>x)break;
			num+=i;
			ans++;
			
		}
		cout<<ans+1;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		ans=0;
		cnt=0;
		for (int j=i-1;j>=1;j--)
		{
			ans+=a[i]-a[j];
			cnt++;
			if (ans>m)break;
			
		}
		if (ans>m)cnt--;
		maxx=max(maxx,cnt+1);
	}
	cout<<maxx; 
	return 0;
}
