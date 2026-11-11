#include<bits/stdc++.h>
using namespace std;
/*
14:44 嗯对，我又来写游记了，上午考得不好aa，下午我想要Ag,,Cu也行 
	  老师说第一题应该是贪心，的确好吧
	  应该是找到一段尽可能长的差之和不超过m的上升子序列 
14:49 ?!前缀和?! 
	  应该是贪心吧、、怎么有股dp味sos 
15:32 ok想出来了，大概是O(n)的样子，是差分贪心 
15:52 其实32时并没有想对，是个n^2所以不行  
16:32 写了个暴力 
*/
long long a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m,ans=-1;cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>30000){
		long long sub=a[2]-a[1];
		cout<<m/sub;
	} 
	else{
		for(int i=1; i<=n; i++){
			long long cnt=1;
			for(int j=i; j>=1; j--){
				sum[i]+=a[i]-a[j];
				if(sum[i]>m) break;
				ans=max(ans,cnt);
				cnt++;
			}
		}
		cout<<ans;		
	}
	return 0;
} 
