#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=1e6+10;
ll label,_,n,k,ans;
vector<ll> e[N];
ll r1,r2,dep[N],len,c[N];
ll r11,r12,r21,r22;
ll rt1,rt2;
void dfsdis(ll u,ll lt){
	dep[u]=dep[lt]+1;
	for (ll v:e[u]){
		if(v==lt) continue;
		if(c[v]!=c[u]) continue;
		dfsdis(v,u);
	}
}
void dfs1(ll u,ll lt){
	c[u]=2;
	for (ll v:e[u]){
		if(c[v]==1) continue;
		if(v==lt) continue;
		dfs1(v,u);
	}
}

bool ud[N];
ll fa[N][25],dfn[N],bl[N],cnt,sz[N];
void init(ll u,ll lt,bool nd){
	fa[u][0]=lt;
	if(nd){
		sz[u]=1;
		dfn[u]=++cnt;
		bl[cnt]=u;
		for (int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];	
	}
	for (ll v:e[u]){
		if(v==lt) continue;
		if(c[v]!=c[u]) continue;
		init(v,u,nd);
		if(nd) sz[u]+=sz[v];
	}
}
ll find_son(ll u){
	for (int i=20;i>=0;i--) if(!ud[fa[u][i]]) u=fa[u][i];
	return u;
}

struct Segmentree{
	ll lazy,maxn,pos;
}t[4*N];
void build(ll q,ll l,ll r){
	t[q].lazy=0;
	t[q].maxn=0;
	t[q].pos=l;
	if(l==r) return ;
	ll mid=(l+r)/2;
	build(q*2,l,mid);
	build(q*2+1,mid+1,r);
}
void pushdown(ll q){
	t[q*2].lazy+=t[q].lazy;
	t[q*2+1].lazy+=t[q].lazy;
	t[q*2].maxn+=t[q].lazy;
	t[q*2+1].maxn+=t[q].lazy;
	t[q].lazy=0;
	return ;
}
void modify(ll q,ll l,ll r,ll L,ll R,ll d){
//	cout<<q<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<"\n";
	if(L<=l&&r<=R){
		t[q].maxn+=d;
		t[q].lazy+=d;
		return ;
	}
	pushdown(q);
	ll mid=(l+r)/2;
	if(L<=mid) modify(q*2,l,mid,L,R,d);
	if(R>mid) modify(q*2+1,mid+1,r,L,R,d);
	t[q].maxn=max(t[q*2].maxn,t[q*2+1].maxn);
	if(t[q].maxn==t[q*2].maxn) t[q].pos=t[q*2].pos;
	else t[q].pos=t[q*2+1].pos;
}
pair<ll,ll> query(ll q,ll l,ll r,ll L,ll R){
	if(L<=l&&r<=R) return make_pair(t[q].maxn,t[q].pos);
	pushdown(q);
	ll mid=(l+r)/2;
	pair<ll,ll> q1={0,mid};
	pair<ll,ll> q2={0,r};
	pair<ll,ll> ans={0,0};
	if(L<=mid) q1=query(q*2,l,mid,L,R);
	if(R>mid) q2=query(q*2+1,mid+1,r,L,R);
	ans.first=max(q1.first,q2.first);
	if(ans.first==q1.first) ans=q1;
	else ans=q2;
	return ans;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	dep[0]=-1;
	ud[0]=1;
	label=read();
	_=read();
	while(_--){
		n=read();
		k=read();
		for (int i=1;i<=n;i++) e[i].clear(),ud[i]=0,c[i]=0;
		for (int i=1;i<=n;i++) for (int j=0;j<=20;j++) fa[i][j]=0;
		for (int i=1;i<n;i++){
			ll u,v;
			u=read();
			v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		cnt=0;
		dfsdis(1,0);
		r1=1;
		for (int i=1;i<=n;i++) if(dep[r1]<dep[i]) r1=i;
		dfsdis(r1,0);
		r2=r1;
		for (int i=1;i<=n;i++) if(dep[r2]<dep[i]) r2=i;
		len=dep[r2];
		init(r1,0,0);
        for (int i=r2;;i=fa[i][0]){
			if(dep[i]==len/2){
				c[i]=1;
				dfs1(r1,0);
				break;
			}
			if(i==r1) break;
		}
		for (int i=1;i<=n;i++) if(!c[i]) c[i]=1;
		
		cnt=0;
		dfsdis(r1,0);
		r11=r1;
		for (int i=1;i<=n;i++) if(c[i]==2&&dep[r11]<dep[i]) r11=i;
		dfsdis(r11,0);
		r12=r11;
		for (int i=1;i<=n;i++) if(c[i]==2&&dep[r12]<dep[i]) r12=i;
		init(r11,0,0);
		len=dep[r12];
		for (int i=r12;;i=fa[i][0]){
			if(dep[i]==len/2){
				rt1=i;
				ud[i]=1;
				break;
			}
			if(i==r11) break;
		}
		dfsdis(rt1,0);
		init(rt1,0,1);
//		cout<<len<<"\n";
//		cout<<dep[r11]<<" "<<dep[r12]<<"\n";
//		cout<<"End1 "<<cnt<<" "<<rt1<<"\n";
//		printf("tree1:\n");
//		for (int i=1;i<=n;i++) if(c[i]==2) cout<<i<<" ";
//		puts("");
		
		dfsdis(r2,0);
		r21=r2;
		for (int i=1;i<=n;i++) if(c[i]==1&&dep[r21]<dep[i]) r21=i;
		dfsdis(r21,0);
		r22=r21;
		for (int i=1;i<=n;i++) if(c[i]==1&&dep[r22]<dep[i]) r22=i;
		init(r21,0,0);
		len=dep[r22];
		for (int i=r22;;i=fa[i][0]){
			if(dep[i]==len/2){
				rt2=i;
				ud[i]=1;
				break;
			}
			if(i==r21) break;
		}
		dfsdis(rt2,0);
		init(rt2,0,1);
//		cout<<len<<"\n";
//		cout<<dep[r21]<<" "<<dep[r22]<<"\n";
//		cout<<"End2 "<<cnt<<" "<<rt2<<"\n";
//		printf("tree2:\n");
//		for (int i=1;i<=n;i++) if(c[i]==1) cout<<i<<" ";
//		puts("");
		
		build(1,1,n);
		for (int i=1;i<=n;i++){
			if(ud[i]) continue;
			modify(1,1,n,dfn[i],dfn[i],dep[i]);
		}
		
		k-=2;
		while(k){
			ll nw=bl[query(1,1,n,1,n).second];
//			cout<<nw<<"?"<<k<<"\n";
			ll x=find_son(nw);
//			cout<<x<<"\n";
			ud[x]=1;
			modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,-1);
			k--;
		}

		printf("%lld\n",query(1,1,n,1,n).first);
	}
}
/*
15:53
感觉先找出直径然后从两个四分点开始慢慢扩展的方案很对吧，好像并不好二分
发现到每个连通块最远的点肯定是叶子
维护每个叶子到连通块的距离？
每次找出最远的叶子，让他到连通块最近的点的对应儿子扩展？
用倍增维护找儿子的过程
问题是怎么找出最远的叶子？
用堆的话可能一次加点会改变一堆位置
相当于给一个子树内的值全部减一？
直接线段树维护，然后每次查找全局最大值及其下标，然后修改维护即可？
感觉很对，上个厕所写下暴力 O(knlogn) 
等下，先拿个小样例玩一下 
应该没问题，发现有一个点是 k=2 先写这个
16：25
？过不去，是写错了还是结论假了？
重新考虑，中点直接断开变成两棵树，然后要分别选择两颗子树的中心？ 
16:40
哦哦哦，前面结论假了，直接中点断开成两棵子树，分别取中心才是对的
剩下就简单了?
17:18
大样例三的第三个点错了？？？多测没清空吗 
为什么啊啊啊，多测没有问题啊 
还是遗憾啊，只有那一个点没过
能拿多少分？我问我自己 
17:46
不服！ 
17:52
可能明白问题了，处理中间的点会有问题 
不会处理，算了
能拿多少分随缘 
*/
/*
0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

0 1
3 2
1 2
2 3
*/
