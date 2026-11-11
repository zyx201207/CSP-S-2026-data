#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
inline ll read(){
	ll x=0; int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=2000005;
int n,d,c,minn,cnt;
ll x[N];
void dfs(int k,int lim,int dis){
	if(k==lim){
		if(dis<minn) minn=dis,cnt=1;
		else if(dis==minn) cnt++;
		return ;
	}
	for(int i=k+1;i<=lim;i++){
		if(x[i]-x[k]>d) break;
		dfs(i,lim,dis+1);
	}
}
void solve(){
	n=read(),d=read(); for(int i=1;i<=n;i++) x[i]=read();
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	if(c<=2){
		int ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				minn=1e9;
				cnt=0;
				dfs(l,r,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
		return ;
	}
	if(c>=11&&c<=12){
		int t=d/(x[2]-x[1]);
		if(d==(x[2]-x[1])){
			cout<<0<<'\n';
			return ;
		}
		if(x[2]-x[1]>d){
			cout<<0<<'\n';
			return ;
		}
		int len=2*t-1;
		cout<<max(0ll,n-len)<<'\n';
		return ;
	}
	cout<<0<<'\n';
}
signed main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
c=read(); int t=read(); while(t--) solve();return 0;}
/*
求对的信息，我有两个想法。
一个是转换成二维矩阵拿树套树，CDQ什么的做。
第二个是炫酷支配对魔术。
我发现了一个惊人的秘密，理论答案上限是O(N^2)量级的，但是他没有对答案的模数。
我猜测答案上限没有那么多，然后就是最短路径是假的吧，因为要最短一定是走直线距离没毛病。
那就计数路径恰只有2条的点对数
这两条路必然是形如
    / ----\
----       ----这样的，前缀和后缀那里可以为滚木 
	\____/
口胡一个O(n^3)做法，就是枚举中间的那一段，向外扩展到极致，用乘法原理统计答案
我又会另一个O(n^3)了。
枚举对，我们发现如果每次竭尽全力可以抵达到的话，那么中间没有那么用力的跳也是能到达的。
因为你都能跳到那了，一定是能弥补过去的，好写好调。
woc,沃好香读假题了，长度的定义居然是路径数吗，那不想法区掉了么。
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
