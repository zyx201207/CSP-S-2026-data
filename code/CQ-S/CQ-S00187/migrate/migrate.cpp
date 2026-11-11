#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool bg;
ll d,x[2000005],ans;
int n,nxt[2000005],to[2000005][21];
struct zt{
	int ans,c,bad;
}bz[2000005][2][2][2];
bool ed;
void solve(){
	ans=0;
	memset(to,0,sizeof(to[0])*(n+1));
	memset(bz,0,sizeof(bz[0])*(n+1));
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)to[i][0]=nxt[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
	for(int i=1;i<=n;i++){
		int pv=i,v=nxt[i];
		for(int tc=0;tc<=1;tc++){
			for(int tbad=0;tbad<=1;tbad++){
				if(nxt[i]==i){
					bz[i][0][tc][tbad].c=2;
					continue;
				}
				int c=tc,bad=tbad;
				if(nxt[pv-1]==v)c+=int(bad)+1;
				if(nxt[pv-1]==v-1)bad=1;
				else bad=0;
				bz[i][0][tc][tbad].bad=bad;
				c=min(2,c);
				bz[i][0][tc][tbad].c=c;
				if(nxt[pv-2]==v)bz[i][0][tc][tbad].c=2;
				if(nxt[pv-2]==v)continue;
				if(c>1)continue;
				if(c==0){
					if(nxt[pv-1]<v-1)bz[i][0][tc][tbad].ans+=nxt[v-1]-max(v,nxt[v-2]);
				}else{
					bz[i][0][tc][tbad].ans+=nxt[v]-nxt[v-1];
				}
			}
		}
	}
	int w=1;
	for(;(1<<(w-1))<n;w++){
		for(int i=1;i<=n;i++){
			to[i][w]=to[to[i][w-1]][w-1];
			for(int tc=0;tc<=1;tc++){
				for(int tbad=0;tbad<=1;tbad++){
					if(bz[i][~w&1][tc][tbad].c>1){
						bz[i][w&1][tc][tbad]=bz[i][~w&1][tc][tbad];
					}else{
						auto x=bz[i][~w&1][tc][tbad];
						bz[i][w&1][tc][tbad]=bz[to[i][w-1]][~w&1][x.c][x.bad];
						bz[i][w&1][tc][tbad].ans+=x.ans;
					}
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		int pv=i,v=nxt[i],c=0;
		bool bad=0;
		int cnt=0;
		while(nxt[v]!=v&&cnt<=5){
			cnt++;
			if(pv-1>=i&&nxt[pv-1]==v)c+=int(bad)+1;
			if(pv-1>=i&&nxt[pv-1]==v-1)bad=1;
			else bad=0;
			if(pv-2>=i&&nxt[pv-2]==v)break;
			if(c>1)break;
			if(c==0){
				if(pv-1<i||nxt[pv-1]<v-1)ans+=nxt[v-1]-max(v,(v-2>=i?nxt[v-2]:v))/*,cerr<<i<<" ["<<max(v,(v-2>=i?nxt[v-2]:v))+1<<','<<nxt[v-1]<<"]\n"*/;
			}else{
				ans+=nxt[v]-nxt[v-1];
			}
			pv=v;
			v=nxt[v];
		}
		if(c<2)ans+=bz[pv][~w&1][c][bad].ans;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)solve(); 
	return 0;
}
/*
显然贪心飞最远的是一定更优的
然后考虑有两条这个是什么情况
考虑肯定是每一步不跳满
然后后面也可以追上去
也就是nxt[u-1]=nxt[u]
当然不是同一个联通块不管他
这样可以限制存在额外的方法 
并且区间中只能换一次

感觉这个限制就比较垃圾
直接数属于非常困难的
因为对于不同的起点还有不同的

然后还有一个性质
l~r的段数是1~n在区间(l,r)内的段点数量或这个其减一
没什么用

考虑区间只有一种的怎么数
就是要求每次跳nxt都不能有nxt[i-1]=nxt[i]，显然可以一次到肯定只有一种，不用管他
但是这个区间边界真的很烦

考虑把nxt建成树考虑
在l的角度有点麻烦，从r的角度看
就是每次走到一个儿子，直到走到一个<=l的点
这真的对吗
也可以走到一个儿子+1的位置，且恰好一次
这感觉也比较困难啊



直接刻画路径吧
要求是：
恰好存在一个u满足：nxt[nxt[u]-1]=nxt[nxt[u]]
并且这个u要：nxt[u-1]<nxt[u]-1 
考虑枚举l去统计答案
如果我从l开始每次跳一个nxt，设当前在v，统计r在v+1~nxt[v]的答案
考虑从v前两个开始的u的数量
如果有一个了，那v-1可以到的就不合法
否则必须v-1可以到的才合法，并且要求v-1要满足上一个v-1到不了它才可以 
依旧要特判第一段
第一段显然全部不合法
第二段的也要特判，因为上一个v-1不存在 
不对，还有一个限制，对于任何v，要有：
nxt[nxt[u]-2]<nxt[nxt[u]]
这个代码显然非常有优化前途的
考虑他的计算答案只和v、pv、c、bad相关
然后关于i的比较完全可以先跑几个位置
那就可以倍增了啊
做完了好吧 




void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)nxt[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
	for(int i=1;i<=n;i++){
		int pv=i,v=nxt[i],c=0;
		bool bad=0;
		while(nxt[v]!=v){
			if(pv-1>=i&&nxt[pv-1]==v)c+=int(bad)+1;
			if(pv-1>=i&&nxt[pv-1]==v-1)bad=1;
			else bad=0;
			if(pv-2>=i&&nxt[pv-2]==v)break;
			if(c>1)break;
			if(c==0){
				if(pv-1<i||nxt[pv-1]<v-1)ans+=nxt[v-1]-max(v,(v-2>=i?nxt[v-2]:v));
			}else{
				ans+=nxt[v]-nxt[v-1];
			}
			pv=v;
			v=nxt[v];
		}
	}
	cout<<ans<<'\n';
}
*/
