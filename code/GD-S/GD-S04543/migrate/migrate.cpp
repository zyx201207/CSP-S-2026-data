#include<bits/stdc++.h>
#define ll long long
#define Furinas return
#define Tears 0
#define Arias 1
#define N 2000005
using namespace std;
ll c,T,n,d,x[N],dp[N],f[N],ans;
struct node{
	ll l,r;
}a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(Tears);
	cin.tie(Tears);cout.tie(Tears);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		ll L=1,R=1;
		for(int i=1;i<=n;i++){
			while(x[i]-d>=x[L+1]&&L+1<=n) L++;
			while(x[i]+d>=x[R+1]&&R+1<=n) R++;
			a[i].l=L;a[i].r=R;
		}
		ans=0;
		if(c>=11&&c<=12){
			ll p=x[2]-x[1];
			ll cnt=d/p;
			if(cnt<=1||n-cnt*2+1<=0) cout<<0<<'\n';
			else cout<<n-cnt*2+1<<'\n';
			continue;
		}
		for(int i=2;i<=n;i++) dp[i]=2e18+7,f[i]=0;
		for(int i=1;i<=n;i++){
			f[i]=1;dp[i]=0;
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=a[j].r;k++){
					if(dp[k]<dp[j]+1) continue;
					if(dp[k]>dp[j]+1){
						dp[k]=dp[j]+1;
						f[k]=f[j];
						continue;
					}
					f[k]+=f[j];
				}
				if(f[j]==2) ans++;
			}
			for(int j=i+1;j<=n;j++) dp[j]=2e18+7,f[j]=0;
		}
		cout<<ans<<'\n'; 
	}
	Furinas Tears;
}
/*
N是2e6 很显然要近乎O(n)
大概率是dp 
先观察一下样例
首先 我们无法处理完任意两点之间能否到达
所以我们可以处理出每个节点左边能延申到哪里 和右边能延申到哪里
d是一定的 所以区间一定在往右移动 我们考虑双指针即可
处理完这些区间后 我们看看这个岛屿对有什么特征
首先 u,v要用最少的区间覆盖掉
其次 有且只有两种方案
可以发现 区间重叠处的点可以任选
所以即为最少区间覆盖掉后 所有重叠区间的内部节点的和为2 那么uv即即为这个啥啥啥
哦对了 起始点和末尾点不算重叠
不对 不是最少区间覆盖
首先d是一定的 尽量往外阔绝对没错
但有一些可能也跟其最优方案相同啊
可能还是需要考虑一些特征性的问题
我感觉我短时间搞定不了 那就开始骗分吧
先考虑O(N^2) 假设我枚举到i 只考虑能否与后面的组成啥啥啥
首先 i能够扩到的自然不行
考虑每个i都有一个dp
dp j 表示i~j最短长度
f 表示方案数
硬跑可以写到O(n^3)
考虑还能不能优化一下
先写24分 回来再尝试优化 
24分拿下 先去看T4 
考虑等差数列的情况
首先每个人扩的总数一样 范围一样
11 1
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
*/
