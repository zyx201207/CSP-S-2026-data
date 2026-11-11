#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e6+10;
int n,m,a[N],sum[N];
int cal(int l,int r)
{
	int len=r-l+1;
	return a[r]*len-sum[r]+sum[l-1];
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(cal(mid,i)<=m)r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 8
-3 -1 2 2 7

4
*/

