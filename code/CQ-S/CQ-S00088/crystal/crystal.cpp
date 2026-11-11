#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=n-1;
	while(l>=1&&sum+(a[n]-a[l])<=m)
		sum+=(a[n]-a[l]),l--;
	ans=max(ans,n-l);
	for(int i=n-1;i>=1;i--)
	{
		sum-=(a[i+1]-a[i])*(i-l);
		while(l>=1&&sum+(a[i]-a[l])<=m)
			sum+=(a[i]-a[l]),l--;
		ans=max(ans,i-l);
		if(l==0)
			break;
	}
	cout<<ans;
	return 0;	
}
/*
input1:
8 1000
-1000 -1 1 1 1 1 1 1
output1:
7
input2:
9 2000
-1000 -1000 -1 1 1 1 1 1 1
output2:
8

只需要 a[i]-a[j] 

我是傻福，这都要 1h ？ 
*/
