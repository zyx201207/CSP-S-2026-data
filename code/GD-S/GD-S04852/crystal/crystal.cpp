#include<bits/stdc++.h>
#define i128 __int128
#define int long long
using namespace std;
int n,m,a[500005];
i128 suf2[500005],suf[500005];
inline bool check(int x)
{
	i128 minn=1e35;
	for(int i=1;i<=n-x+1;i++){
		int j=i+x-1;
		minn=min(minn,suf2[i]-suf2[j]-(j-i)*suf[j]);
	}
	return minn<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i;i--) suf[i]=suf[i+1]+a[i+1]-a[i];
	for(int i=n-1;i;i--) suf2[i]=suf2[i+1]+suf[i];
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return cout<<ans,0;
}
/*
15:00开写
二分答案+枚举选的区间的端点？我希望是正确的 
wc,看错题了！！！水晶只能升！！！ 
完了，15:55才过！ 
争争争！ 
*/ 
