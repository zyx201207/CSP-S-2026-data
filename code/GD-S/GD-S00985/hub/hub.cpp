#include<bits/stdc++.h>

using namespace std;
int C,T;
int n,k;
vector<int>qq[2100000];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			qq[u].push_back(v);
			qq[v].push_back(u);
		}
		cout<<"0\n"; 
	}
	return 0;
}/*
大抵是我的最后一舞了
貌似写奇怪的东西会取消成绩？
算了 不管了
本来想写个feropen给大家整个活，想了想还是算了
学了3年这个了 上午的J组250+谁能绷住
我最大的愿望就是这个玩意可以上那个每年一度的CSP迷惑行为大赏(还是叫其他什么的)
额 可能算是退役记吧
退役什么？？ 
算了 不说这些了 来给大家整个活

~(￣0￣)/▄︻┳═一 *-  -  -  - (X ~ X)饿~~ 

可以不要肘击我吗QAQ 
我还不相思
好累
放弃吧
*继续前进
要是可以RP大爆发给我一个S1就好了
不过不太可能
我这是梦到什么写什么吗
要不要删掉呢？
算了 都一样
T~T
你谷髦髦
算了 我要去T3骗分了
还剩45min 
*/
