#include <bits/stdc++.h>
#define int long long 
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=5e5+5;

void fre(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}

int a[N],last[N],dp[N],tag[N],n,m,ans[N],c[N];

struct block{//计算每个点贡献的区间 
	int l,r;
}q[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i];
	}
	E(i,n,1){
		if(last[a[i]]){
			dp[i]=i;
			q[i].l=i+1;
			q[i].r=last[a[i]];
		}else{
			last[a[i]]=i;
			dp[i]=dp[i+1];
		}
		tag[dp[i]]++;
	}
	F(i,1,n){
		if(last[a[i]]!=i)tag[dp[last[a[i]]]]+=tag[i];
		else tag[dp[i]]+=tag[i];
	}
	F(i,1,n){
		if(!q[i].l)continue;
		c[q[i].l]-=tag[i];
		c[q[i].r+1]+=tag[i];
	}
	F(i,1,n){
		c[i]+=c[i-1];
		
	}
	F(i,1,n){
		c[i]+=i;
		ans[a[i]]+=c[i];
	}
	F(i,1,m)cout<<ans[i]<<" ";



	Luogu _DEQUE_;
}//172.16.12.5 Trick||Treat!
//remember to check your code,you didn't use "define int long long" or "fre()"
/*
好吧前面思路假了/ll
我们考虑到每个数最多留一个，所以其实可以留最后一个可能被留下的。
这个数留不了，当且仅当它被区间包含 
但是怎么维护这个区间呢
估计还得是队列才能就我/ll
很容易发现他会被一个区间包含，所以我们动态加点然后考虑如何退
唉我只会 n^2 吗
感觉还是要维护神秘区间啊 
好像主席树dp是对的 
重新捋一下。
我们直接线段树是很显然的
区间左右具有单调性！
所以区间的就是可以直接做! 
然后dp 处理应该是简单的。
直接指向last 即可。
然后思考一下权值计算
tag[dp[i]]+=tag[i]
然后的话前缀和一下tag就可以直接计算了。
直接开干！
哦对另外提一下，二次线段树！ 
唉不对啊。
等会，每个点新建一个区间不就好了
区间直接存储！
tag 直接计算权值！ 
根本不需要持久化！ 
啊啊啊啊啊啊啊啊啊妈妈我ak了！！！！！！！！！！！！！！！！！ 
*/ 
