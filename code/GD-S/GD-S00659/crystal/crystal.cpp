#include<bits/stdc++.h>
#define prior priority_queue<int,vector<int>,greater<int>> 
#define int long long
#define N 500010
using namespace std;
int n,m,a[N],deq[N],sum[N],ans[N],maxx;
/*

取一个中间值，能够使得两侧分布的点差最小 

枚举中间值-> 二分搜两边 

*/
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=n;i>=1;i--) //枚举i 
	{
//		cout<<endl<<'-'<<endl;
		int l=1,r=i,mid,tmp;
		while(l<r) //二分j
		{
//			cout<<l<<' '<<r<<endl;
			mid=(l+r)/2;
			int j=i-mid;
			tmp=j*a[i]-sum[i-1]+sum[i-j-1];
			if(tmp>m) l=mid+1;
			else r=mid;
		}
//		cout<<i<<' '<<l<<' '<<r<<endl;
		ans[i]=i-l;
	}
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,ans[i]);
	}
	cout<<maxx+1;
	return 0;
}
/*

pq=prior();

dp[i][j]=(i-j)a_i-c_{i-1} 表示第i位前j项宝石合并代价 

*/
