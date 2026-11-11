#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using i128=__int128;
using pii = pair<int, int>;
const int N=5e5+9,inf=1e9+9;
ll a[N];

void ot(i128 x){
	if(x==0)return;
	ot(x/10);
	cout<<(int)(x%10);
}

void solved(){
	int n;ll m ;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1;i128 now=0;//当前价值  先使用ll试试
	int ans=0; 
	for(int r=1;r<=n;r++){
//		cout<<"in "<<l<<' '<<r<<' '<<now<<endl;
		if(r!=1)now+=(i128)(a[r]-a[r-1])*(r-l);
		while(now>m)now-=a[r]-a[l],l++;
		ans=max(r-l+1,ans);
//		cout<<"ot "<<l<<' '<<r<<' '<<now<<endl;
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

3

fc crystal1.ans crystal1.out
fc crystal2.ans crystal2.out
fc crystal3.ans crystal3.out
fc crystal4.ans crystal4.out
*/
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solved();
	return 0;
} 
/*
keep thinking  determined  calmed down!
一道序列问题
感觉像二分
我们需要改变最多m次使得尽量多的元素的价值相同
注意了，每次都是增加1 的价值 
我们很容易想到钦定一个价值，然后看看改m次能使多少元素等于它 
我们排个序明显会更好做 
思考一下正解

我们肯定是选择一个价值，然后让其他的价值尽量靠近这个价值
就是以它为中心扩散出去，不对，应该是让它前面的靠近它
所以这样它前面的元素本身离他差的越小的就越容易靠近它
那么直接往左扫一遍递减m为0时就停下即可
此时，我们会得到一个cnt数字,就是一个答案

那么每个数我们都这样做一下往左扫
得到一个 O(n^2) 的做法 获得45分 
不过这个实际上是跟值域相关的，取值域和n的min
所以可以通过 前12个测试点，获得 60 分
 
我们可以尝试优化 
前缀和，我们会发现，前面的数到当前位置 的 数 w 的差值
实际上可以计算
我们列出来如下
OOOOOOO...XXX 其中.表示当前， X 表示大于， O 表示小于
我们可以正向扫描！！！！
不难发现，前面的差值是可以累计的
所以用双指针，然后因为m固定，而价值单增，符合双指针要求
 
大体思路，我们维护一个到当前数 w 的区间 
其中区间中所有数距离 w 的价值总和小于等于w 
我们不用缩点，因为无所谓，而缩点可能会错 
假设元素都不相等

r记录的是当前数，l 记录的是区间的左端点 
我们迁跃的时候就是后方的价值减前方的价值 
然后乘上 r-l+1 为当前总价值
当总价值大于m的时候，我们右移左端点
最后，每一个合法的 l , r ,它的len 更新答案

得解
注意最大1e18 可能会超过限制，所以我们可能需要 i128 

看来是A 掉了
等会写下拍子
试一下i128 能不能写 
能写 就 i128 吧 
*/






