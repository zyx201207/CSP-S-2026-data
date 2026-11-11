#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],last[maxn],cnt[maxn];
int pre[maxn],suf[maxn];
//pre[i] 表示 [1,i] 的卡牌集合大小
//suf[i] 表示 [i,n] 的卡牌集合大小 
int bit[maxn],ans[maxn];
int lowbit(int x){return x&-x;}
void add(int id,int v){
	for(;id<=m;id+=lowbit(id))bit[id]+=v;
}
int query(int id){
	int res=0;
	for(;id>0;id-=lowbit(id))res+=bit[id];
	return res;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		cnt[a[i]]++;
	}
	// 第 i 局中卡牌 j 被留下
	// 即在 [i,n] 中的最后一张 j 卡牌，它前与后不存在相同的卡牌
	//修正 11:37 ：前面与后面重复的卡牌中，数量为偶数张 
	// 设最后一张卡牌 j 位置是 k
	// 相当于固定 [k+1,n]，求 [i,k-1] 与 [k+1,n] 的卡牌集合不存在交集 的数量 
	// 朴素时间复杂度 O(nm+n log_m)，空间复杂度 O(n+m)
	// 优化：已知 [k+1,n] 卡牌集合大小为 suf[i+1]
	// 我们要求的就是 pre[1~k-1] 中，<= 交集大小 - suf[k+1] 的数量！这可以树状数组维护！
	// 如何求交集？ -> 如何求并集？复杂度 O(nm) 不可取。-> 数组计数可行吗？
	// 保证所有卡牌都出现过 -> 若 j 数量 > 1 则交集 = m；
	// j 数量 =1 时呢？交集 = m-1！ 
	// 答案为 pre[i] i<k 且 pre[i]<And-suf[k+1] 的数量，可以动态维护 11:22 
	set<int>st;
	for(int i=1;i<=n;i++){
		st.insert(a[i]);
		pre[i]=st.size();
	}
	st.clear();
	for(int i=n;i>=1;i--){
		st.insert(a[i]);
		suf[i]=st.size();
	}
	for(int j=1;j<=n;j++){
		int And=(cnt[a[j]]==1?m-1:m);
		int need=And-suf[j+1];
		ans[j]=query(need);
		if(need==m)ans[j]=n-1;
		// ans[j] 为 i<j 且 pre[i]<=need 的个数 
		add(pre[j],1);
	}
	//cout<<'\n';
	for(int i=1;i<=m;i++){
		int k=last[i];
		cout<<ans[k]+1<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
