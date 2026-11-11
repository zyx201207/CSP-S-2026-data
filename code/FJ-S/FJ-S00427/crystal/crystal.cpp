/*
T1 crystal
14:50 过了所有大样例，这是好事 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ljl;
const int N=5e5+5;
int n,ans;
ljl m,a[N],sum[N];
bool chk(int mid,int pos)
{
	ljl s=sum[pos-1]-sum[mid-1]-a[pos]*(ljl)(pos-mid);
	return m+s>=0;
}
int lwb(int pos)
{
	int l=1,r=pos,mid,ans=r;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(chk(mid,pos))ans=mid,r=mid-1;
		else l=mid+1;
	}return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[i];
//	cout<<chk(1,3)<<'\n';return 0;
	for(int i=1;i<=n;++i)
		ans=max(ans,i-lwb(i)+1);
	cout<<ans<<'\n';
	return 0;
}

