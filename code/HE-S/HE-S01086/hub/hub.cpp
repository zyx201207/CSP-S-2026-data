/*
HE高一才两百出头是不是没戏了。据说他们hzoi都是300+大手子。我要完蛋了。
能去WC吗？希望分数线低一点。去玩一趟总比不去好。 

-19 min
马上开始了， 很紧张。
联系一下键盘。
the quick brown fox jumps over the lazy dog
the lazy dog jumps over the quick brown fox
还可以。。
the quick brown fox jumps over the lazy dog
the quick brown fox jumps over the lazy dog
莫辞更坐弹一曲、为君翻作琵琶行。
不是很能盲。还是要看。
没啥大要求，不挂分就行。
Anything is posible.
屏幕相对于我来说有点高了。
-10 min
We aren't have a windy walk here.This is Real Life.
Forwar
1. 枚举一下a_i 跑个贪心。

2. Floyd一下吗？没看太懂。

题面诈骗了。。 w i 有个P用。。
那说白了就是枚举俩D？？然后没了？？？
啥破题。。。
我感觉这个nm可能有点启发了，因为一般就是 n点m边。

为啥他妈的快读比cin慢？

3.大分类讨论状物？

大概瞎写了一下，加了点特判，随机数据表现很好。但是等差数列过不去。特判了一下。所以至少8pts 

4.贪心dp乱搞？？为啥这个n都这么大！！
没时间了。2^n = 15; 

220 min 最终得分 [223,315]。后面的界是及其松的。
*/ 

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P(1e9+7);
ll kuaishumi(ll x,ll b){
	if(!b)return 1;
	ll t(kuaishumi(x*x%P,b/2));
	if(b&1)t=t*x%P;
	return t; 
} 
const int MXN(100);
int fa[MXN];
int n,k;
void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int c,t; 
#define is(x,i) ((x)&(1<<(i-1))) 
vector<int>E[MXN]; 
int dis[MXN][MXN];
void dfs(int rt,int x,int fa){
	for(int v:E[x]){
		if(v==fa)continue;
		dis[rt][v]=dis[rt][x]+1;
		dfs(rt,v,x);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)E[i].clear(); 
	for(int i=1;i<n;i++){
		int _,__;
		cin>>_>>__;
		E[_].push_back(__);
		E[__].push_back(_);
	}
	for(int i=1;i<=n;i++)
		dfs(i,i,0);
	int fres=0x3f3f3f3f;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k)continue;
		init();
		int ltk=__builtin_popcount(i);
		int res=0;
		for(int j=1;j<=n;j++)
			if(is(i,j))
				for(int k:E[j])
					if(is(i,k))
					{
						int u=find(j);
						int v=find(k);
						if(u!=v)ltk--;
						fa[u]=v;
					}
		if(ltk>2)continue;
		for(int j=1;j<=n;j++){
			int pres=0x3f3f3f3f; 
			for(int k=1;k<=n;k++)if(is(i,k))pres=min(dis[j][k],pres);
			res=max(res,pres);
		}
		fres=min(res,fres);
	}
	cout<<fres<<endl;
}
signed main(){
//	int T0(clock());
	ios::sync_with_stdio(0);cin.tie(0); 
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve(); 
	return 0;
}
