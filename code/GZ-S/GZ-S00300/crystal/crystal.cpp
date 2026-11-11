//GZ-S00300 付滨诚 贵阳一中 
/*
第一题很显然题目告诉我们增加具有单调性
可能与二分有关我们注意到选没有初始值的位置一定是亏的
所以我们选择有水晶球的位置进行一个贪心
每次用l r维护下标表示l~r 被选中统计花费
滑动窗口去做
复杂度O(n) 
速切
下一题 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],l,r,cost,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	l=1,r=1;
	for(;r<n;){
		r++;
		int cost1=cost+(a[r]-a[r-1])*(r-l);
		while(cost1>m){
			cost=cost-(a[r-1]-a[l]);
			l++;
			cost1=cost+(a[r]-a[r-1])*(r-l);
		}
		if(cost1<=m) cost=cost1;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
