#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000010],pre[1000010],sum;
long long check(long long len)
{
	for(int i=1;i<=n-len+1;i++)
	{
		long long r=i+len-1;
		if(a[r]*len-(pre[r]-pre[i-1])<=m)
		{
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	long long l=1,r=n,ans=1;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
1 1 2 4 1
好吧饭堂了直接排序+二分就行了,还以为合成要连续呢
*/
