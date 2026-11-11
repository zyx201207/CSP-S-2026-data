#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define AC WA
const int N=5e5+10;
LL a[N],sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(LL i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	LL ans=1;
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
//	cout<<endl;
	for(LL i=n,j=n-1;i>=1;i--)
	{
		while((a[i]*(i-j)-(sum[i-1]-sum[j-1]))<=m&&j>=1) j--;
		j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
//我好像AC了！！！！！！！
//无敌！！！
//半小时切了！！！！！
//第一次切ST1
//！！！！！
//我太高兴了 
