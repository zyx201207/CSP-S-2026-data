#include<bits/stdc++.h>
using namespace std;
const int M=500010,N=510;
int c,n,m,D,q;
int A[M];
struct Egde{
	int nxt,to,d;
}e[(M+N)<<1];
int h[M+N];
int cnt=0;
void add(int u,int v,int d){
	e[++cnt].d=d;
	e[cnt].nxt=h[u];
	e[cnt].to=v;
	h[u]=cnt;
}
int g[N+M];
void dfs(int u,int fa){
	for(int i=h[u];i;i=e[i].nxt){
		int v=e[i].to;
		int d=e[i].d;
		if(v==fa)continue;
		dfs(v,u);
		g[u]=g[v]+d;
	}
}
long long mindis=0x3f3f3f3f;
int vis[M];
long long dis[M][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			if(vis[a]!=0){
				mindis=min(mindis,1ll*vis[a]+t);
			}
			if(c==21||c==20){
				dis[a][i-1]=t;
			}
			vis[a]=t;
			add(i+m,a,t);
			add(a,i+m,t);
		}
	}
	if(c==20||c==21){
		for(int i=1;i<=q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			long long ans=0x3f3f3f3f;
			ans=min(dis[a][0]+dis[b][0],ans);
			ans=min(dis[a][1]+dis[b][1],ans);
			ans=min(dis[a][1]+dis[b][0]+mindis,ans);
			ans=min(dis[a][0]+dis[b][1]+mindis,ans);
			printf("%lld\n",(ans+A[a]+A[b]));
		}
		return 0; 
	} 
	if(7<=c&&c<=11){
		dfs(1,0);
		for(int i=1;i<=q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",(A[a]+A[b]+abs(1ll*g[a]-g[b])));
		}
		return 0;
	}
	return 0;
}
/*
20 2 9 20 10
1 2 3 4 5 6 7 8 9
6 1 3 2 1 3 2 6 5 7 8 8 3
7 2 9 4 4 5 6 6 7 7 2 8 1 9 4
*/
//15：00 
//啥啊
//橙蓝紫黑是吧
//15：25
//有点像图论建模
//15:34
//建出来了，打不全
//1--6可以直接floyd
//16:05
//floyd怎么打挂了
//16:20
//第四个大样例过了
//特A出来 pts+=20 
//16:40
//感觉像是把正解想出来了
//建纯车图跑floyd
//17:22
//蒟蒻难以实现上述算法
//20、21号测试点过了
//pts+=8
//当前100+28+0+0=128
//18:15 
//回去我要打10遍floyd的板子！ 
/*
我常常追忆过去
生命瞬间定格在脑海，我将背后的时间裁剪、折叠、蜷曲，揉捻成天上的朵朵白云
云朵之间亦有分别：积云厚重，而卷云飘渺。
生命里令人震撼的场景掠过我的思绪便一生无法忘怀 ，而更为稀松平常的往事在时间的冲刷下只留下些许残骸 
没时间了，不打了
我该在哪里停留？我问我自己
*/ 
