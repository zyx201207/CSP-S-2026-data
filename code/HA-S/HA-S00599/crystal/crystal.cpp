#include<bits/stdc++.h>
#define ll long long
#define AC return 0
using namespace std;
const int N= 500050+77;
ll n,m,ma=1,ans=0,a[N],sum[N];
void check(ll xi)
{
	ll v=a[xi];
	ll l=1,r=xi,mid=(l+r)/2;
	while(l!=r)
	{
		mid=(l+r)/2;
		if(v*(xi-mid+1)-(sum[xi]-sum[mid-1])>m) l=mid+1;
		else r=mid;
		//cout<<"sum[xi]:"<<sum[xi]<<" mid:"<<mid<<" sum[mid-1]:"<<sum[mid-1]<<" l:"<<l<<" r:"<<r<<"\n";
	}
	ma=max(ma,xi-l+1);
	return;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	for(int i=n;i>=2;i--)
	{
	check(i);
	//cout<<"ma:"<<ma<<" i:"<<i<<"\n";
	ans=max(ans,ma);	
	}
	cout<<ans;
	AC;
}
//注意到v一定属于a 假设答案是一个升序集合{a1,a2,...,an}那么显然令an=v最优
//另有性质对于v=an,显然按照递减序优先考虑答案 
//因此考虑枚举每个ai,在前缀和优化下进行二分答案
//当l与r间元素数目为偶数时，mid向下取，换言之，mid可能始终等于l，因此使得l=mid+1
//综合看来，复杂度控制在O(N*logN)=1e7 可以接受
//GoodBye OI (;
