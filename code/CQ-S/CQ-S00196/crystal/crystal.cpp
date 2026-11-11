#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
long long n,m;
long long ans;
long long bs(long long l,long long r,long long i){
	while(l<=r){
		long long mid=(l+r)/2;
		if(sum[mid]-(n-mid+1)*(a[n]-a[i])-(sum[i+1]-(n-i)*(a[n]-a[i]))<=m){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	} 
	return i-r; 
}
int main(){
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4in.txt","r",stdin);
//	freopen("crystal4.txt","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(long long i=n;i>=1;i--){
		sum[i]=a[n]-a[i]+sum[i+1];
	}
	for(long long i=n;i>=1;i--){
		ans=max(ans,bs(1ll,i,i));
	}
	cout<<ans;
	return 0;
}
/* 
5 8
-3 -1 2 2 7
5 5
1 2 4 8 9
*/
/*
不知道今年cq有没有迷惑行为大赏。 
反正写不出其他的，还不如尝试上电视。
今年j组感觉比去年难，我也不知道,以前没考过csp。
上午j组t1没注意到没有e，t2我也是成功的把o(n)优化成了o(nlogn),t3t4没思路，估计是2=。 
没怎么刷题（可能是作业太多了），根据cq初赛分数线，我推测今年线不是很高。 
冷知识我们英语老师叫做crystal。 
我觉得这道题挺简单的，思维和代码复杂度都不高，但是调试了很久，反正最后大样例过了。
有点烦，需要自己强转in out的格式。 
我右边那个写了三道题，感觉很强。 
注意力不是很集中，感觉今天喝的三瓶桂花乌龙没啥用（虽然但是桂花真的很好喝）。 
我不知道有没有人看我的代码。 
我想要在谷子上拥有勾，可以加咕值，也可以成为受信任的用户。 
t2不想写了，希望是2=。 
我的模拟，骗分和暴力能力堪忧，应该找时间练练。 
希望我不是我认识的人里面考的最差的，但是也祝贺大家。 
初一看起来还早，实则很晚了。 
其实没什么好写的，我也不敢写抽象的，怕禁赛。 
*/
