#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N],sum,ans,cnt=1;//cnt指针中的个数，ans最大时的个数 ,sum需要加多少 
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=1;
	while(r<=n)
	{
		while(r<=n&&(a[r+1]-a[r])*cnt+sum<=m)
			sum=(a[r+1]-a[r])*cnt+sum,cnt++,r++;	
		ans=max(cnt,ans);
		cnt--,sum-=a[l],l++;
	}
	cout<<ans;
}//Oct31==Dec25? $$￥￥ 
