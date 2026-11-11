#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
int n;
ll m,a[N],d[N],k[N],sum[N];
bool check(int len){
	for(int i=1;i+len-1<=n;i++){
		int j=i+len-1;
	//	now=(ll)k[j]-(i-1)*(a[j]-a[i]);
		
		ll now=(len-1)*a[j]-(sum[j-1]-sum[i-1]);
		if(now<=m){
	//		cout<<now<<" "<<len<<"\n";
			return 1;
		}
	}
//	cout<<now<<" "<<len<<"\n";
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++)cout<<k[i]<<" ";
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		k[i]=k[i-1]+(i-1)*d[i];
		sum[i]=a[i]+sum[i-1];
	}

	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2+1;
		if(check(mid))l=mid;
		else r=mid-1; 
		
	}
	cout<<r;
	return 0;
} 
/*
16:26 大样例神秘掉了，怀疑不是炸了就是二分过于优秀
 可能有笔误？ 












只能加不能减->肯定是从小的开始往大的找？
但是其实不一定要最左边的 ** 

long long 是可以存下的 
存在负数

排序
差分？
维护一个数组表示将前面的全部加到i需要的操作数
考虑临项交换？这什么神秘东西

莫非是dp？考虑区间dp!?
但是数据范围好像不允许区间dp
 
找中位数会不会是最优的？？
貌似不会是最优的，因为贡献不一定随代价的上涨而增加
不对？

二分吗？
二分答案，二分最多能够合成的水晶
好像是不可的，二分复杂度logn*check复杂度n*

正解一定是n*log n 复杂度的 
我对于正解的估计是一个类似前缀和的神秘数组能够o1计算出花费
然后二分一个len，枚举起点 


 
*/


/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7 
*/
