#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,station[500005],ways[505][50005],values[505][50005];
ll ans;
struct roadd{
	int nexts;
	int times;
};
vector<roadd>roads[500005]; 
//bool cmp(ll x,ll y){
//	return x<y;
//} 
//ll lmax(ll a,ll b){
//	return a>b?a:b;
//}
//inline ll readl(){
//	ll l=1,r=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9'){
//		if(ch=='-')l=-l;
//		ch=getchar(); 
//	}
//	while(ch>='0'&&ch<='9'){
//		r*=10;
//		r+=ch-'0';
//		ch=getchar(); 
//	}
//	return r*l;
//}
inline int read(){
	int l=1,r=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')l=-l;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		r*=10;
		r+=ch-'0';
		ch=getchar(); 
	}
	return r*l;
}
void dfs(int now,ll sum,bool sm[],int t){
	if(sum<0)return;
	if(now==t){
		ans=min(ans,sum);
		return;
	}
	sm[now]=false;
	for(auto nowt:roads[now]){
		if(sm[nowt.nexts]){
			sum+=nowt.times;
			dfs(nowt.nexts,sum,sm,t);
			sum-=nowt.times;
		}
	}
	sm[now]=true;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++)station[i]=read();
	for(int i=1;i<=n;i++){
		ways[i][0]=read();
		for(int j=1;j<=ways[i][0];j++){
			ways[i][j]=read();
			values[i][j]=read();
		}
		for(int j=1;j<ways[i][0];j++){
			for(int e=j+1;e<=ways[i][0];e++){
				bool croad=true;
				for(int l=0;l<roads[ways[i][j]].size();l++){
					if(roads[ways[i][j]][l].nexts==ways[i][e]){
						croad=false;
						int r=0;
						while(roads[ways[i][j]][r].nexts!=ways[i][e])r++;
						roads[ways[i][j]][l].times=min(values[i][e]+values[i][j],roads[ways[i][j]][l].times);
						roads[ways[i][e]][r].times=min(values[i][e]+values[i][j],roads[ways[i][e]][r].times);
						break;
					}
				}
				if(croad){
					roadd ls;
					ls.nexts=ways[i][e];
					ls.times=values[i][j]+values[i][e];
					roads[ways[i][j]].push_back(ls);
					ls.nexts=ways[i][j];
					roads[ways[i][e]].push_back(ls);
				} 
			}
		}
	}
	bool pp[m];
	for(int i=1;i<=q;i++){
		for(int i=1;i<=m;i++)pp[i]=true;
		int f,t;
		f=read();
		t=read();
		ans=LONG_LONG_MAX;
		dfs(f,0,pp,t);
		ans+=station[f]+station[t];
		printf("%lld\n",ans);
	}
	return 0;
} 
/*
CCF你真棒……这题根本不会……
想玩changed、三角洲、phigros、CSGO、MC、RFS、异环啊啊啊啊……根本写不动
16:33：T2好像有思路了，用DFS？ 
16:50：构思得差不多了，努力写代码…… 
17:04：预处理特判部分写完啦！
17:10：预处理写完啦！！！ （已经80多行了） 
17:32：T2写完啦！ 
18:01：T2炸了，有的答案偏大 T_T 想吃猫条 喵喵~ 
18:15：改出来了！这编译器有问题啊！！！为啥我函数里改变变量的值，原本用于导入的那个变量也会变啊？？？我也没写&或者*啊 
*/ 
