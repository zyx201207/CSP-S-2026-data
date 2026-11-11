#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define int long long
#define N 500050
using namespace std;
//I AK IOI
//coder:数字和每句话&&shuzihvh
//看题时间:14:30
//complete time:15:05
//思考过程:
/*
1.所有水晶都只能变成一个已确定的水晶（开始coding） 
这是正确的！！！！！！！！ 
5 6
1 2 3 12 99	只能变成3
5 6
1 2 3 5 99 变3和变4的ans是一样的 如果能让所有变成a[i]+k的值且a[i]+k<a[i+1]那么也一定能变成a[i] 
因为a[i]+k没出现过,所以ans是一样的,花费的代价还更小 证毕
5 6
-5 -4 -3 -2 -1 
2.发现：crystal4.in是WA的。
ans:315275
myans:313324 
思考：debug发现313324 到 315275中有很多26只比前面的25差1
从头开始是错的,要一个一个试
气煞我也！！！！！！！！ 
//对于一个已经确定的水晶a[j]和从需要变的地方a[i]:
//需要变化:(j-i)*a[j]-(s[j]-s[i-1])
//那就二分！O(nlogn) 
//315275！！！！！！！！
答对了！！！！！！
二分牛逼！！！ 
哦对了crystal2这个时候又错了！！！！
//改一下,改成l=0的时候，这就对了嘛
牛逼！ 
*/
// 不要爆零！！！
//算法:不知道是什么，贪心吧 
int read(){
	int x=0,f=1,c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
int n,m,a[N],s[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);//前缀和求出
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int j=n;j>=1;j--){
		int l=0,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if((j-mid)*a[j]-(s[j]-s[mid-1])>m)l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,j-l);  
	}
	printf("%lld",ans);
	return 0;
}
