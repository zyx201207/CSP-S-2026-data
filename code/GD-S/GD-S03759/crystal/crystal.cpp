#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,mid,sum,a[500005],pre[500005];
int check(int k)
{
	for(int i=k;i<=n;i++)
	{
		int sum=0;
		for(int j=i-k+1;j<=i;j++) sum+=a[j];
		if(k*a[i]-pre[i]+pre[i-k]<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m,l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)==1) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
}
/*
究竟是哪种人会把排序前的前缀和拿去用然后检查一个小时才检查出来，一开始就知道咋做结果15:37才做完 
100+0+eps+0
AFOed
*/
