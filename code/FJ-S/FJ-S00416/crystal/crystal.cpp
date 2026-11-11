#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=5e5;
int n,m;
int ans;
int a[N+5];
int pre[N+5];
/*
将区间[l,r]全部同化成a_r需要的代价是w(l,r)=a[r]*len-sum(l,r)
w(l,r)一定大于w(l+1,r)，有单调性，所以可以直接二分最优的（最右边）l，做完了 
*/
int sum(int l,int r){return pre[r]-pre[l-1];}
signed main()
{
	cin.tie(0)->sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
//	for(int i=0;i<=n;i++) cout<<pre[i]<<" ";
//	cout<<"\n";
//	cout<<sum(1,4)<<"\n";
	for(int i=1;i<=n;i++)
	{
		/*
		//先暴力看结论 
		for(int j=i-1;j>=1;j--)
		{
			int len=i-j+1;
			int w=a[i]*len-sum(j,i);
//			if(i==4 && j==1) cout<<w<<"\n";
			if(w>m) continue;
			ans=max(ans,i-j+1);
		}
		*/
		//写二分
		int l=0,r=i;
		while(l<r)
		{
			int mid=(l+r)>>1;
			int w=a[i]*(i-mid+1)-sum(mid,i);
			if(w>m) //太左边了，往右边找，mid不可取
				l=mid+1;
			else r=mid; 
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
