#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
bool judge(int k){
	for(int i=1;i<=n;i++){
		if(k>i) continue;
		int res=a[i]*k-(sum[i]-sum[i-k]);
		if(res<=m) return true;
	}
	return false;
} 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(judge(mid)==true){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%lld",ans); 
	return 0;
}
/*
就是通过最多 m 次操作使得尽量多的水晶能量值相同 

有点像二分答案加前缀和 
二分答案最多能用多少颗水晶合成一个大水晶，再用前缀和判断
因为想要用若干颗能量值为 a_i 的水晶合成大水晶，
那变的肯定是比 a_i 能量值小的水晶
反正操作只能加就可以用前缀和 
想到正解了！！！！ 

2:52 p.m.打完正解

2:55 p.m.过完大样例 

时间复杂度：O(NlogN)
难度：yellow  
*/
