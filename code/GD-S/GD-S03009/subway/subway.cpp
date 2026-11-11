#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a;
int k[500010];
long long b,ans;
long long w[500010];
map <int,long long> t[510];         
long long f[510][510];
vector <int> pass[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %lld",&a,&b);
			pass[a].push_back(i);
			t[i][a]=b;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				f[i][j]=1e17;
			}
		}
	}
	int len,u,v;
	for(int i=1;i<=m;i++){
		len=pass[i].size();
		for(int a=0;a<len;a++){
			u=pass[i][a];
			for(int b=0;b<len;b++){
				v=pass[i][b];
				if(a!=b){
					f[u][v]=min(f[u][v],t[u][i]+t[v][i]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&j!=k&&i!=k){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	int x,y,lenb;
	while(q--){
		scanf("%d %d",&x,&y);
		len=pass[x].size();
		lenb=pass[y].size();
		ans=1e17;
		for(int i=0;i<len;i++){
			u=pass[x][i];
			for(int j=0;j<lenb;j++){
				v=pass[y][j];
				ans=min(ans,f[u][v]+t[u][x]+t[v][y]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
0.注意到地铁线路数<=500，每个站的经过地铁数<=20，可以这样处理
 
1.记录每一个地铁站经过的地铁编号 和 每一条地铁可以直接换乘哪些地铁及所需时间（即floyd初始化） 

2.因为只计算步行时间 
所以对地铁线路进行floyd 
floyd[i][j]表示从i号线直接或间接换乘至j号线，所需的步行时间  
时间复杂度为O(n^3)=O(500^3) 

3.对于每一组询问
看看起点和终点的有哪些地铁编号
由于每一个地铁站的经过线路不超过20条
所以最多查询20*20=400次
答案为最小值+进出站时间 
时间复杂度为O(q*d^2)=O(10^5*400)=O(4*10^7)
*/ 
