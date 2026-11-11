//GZ-00400 毕节梁才学校 张静峰 
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
	卧槽，我想出来了，我真他妈是个大聪明
	
	怪不得题目的m,n做的这么奇怪
	把每一条地铁线看作一个点，
	那么这个地铁线经过的所有的点有其他地铁线经过就相当于链接了这条地铁线与其他地铁线
	
	好，一共500个点
	每个点一共有k[i]*d条边
	合起<1e7 
	综合一下大约在1e6左右
	
	500个点 1e6条边不可能，取最小值就行，所以用链接矩阵 
	500个点，250000条边，多元最短路 
	
	想用floyd(必超时） 
	
	但有点擦遍了， 
	
	等等，题目问的是转折点，也就是说最多500条问题
	试试dijkstra 
	 
*/ 

/*
	0.输入（要记录下每条线的所有点），每一个点有哪些线经过给他记录下来 (完成） 
	1. 遍历每一个点，用连接矩阵把新点之间的边记录下来(完成） 
	2.转为链式前向星(完成） 
	3.dijkstra() 
	 
*/

//0.
const int N=510;
const int M=250010;
const int P=5e5+10; 

int n,m;

int v[P];//进站时间 
int d,q,c;

struct OP{
	int id,t;//这是用来记录原点的 
};

vector<OP> K[P];

//待会要用 
//2.转链式前向行 
int to[M];
int nt[M];
LL w[M];
int h[N]; 

int idx;
void add(int x,int y,int z){
	to[idx]=y;
	nt[idx]=h[x];
	w[idx]=z;
	h[x]=idx++;
} 


//1.构建连接矩阵 

LL g[N][N]; 
LL D[N][N];

//3.dijkstra()

bool U[N];//记录第i个点查询过没有 
bool V[N][N];//定义为二维，省时间 

typedef pair<LL,int> PII;
priority_queue<PII,vector<PII>,greater<PII> > hp;

void dijkstra(int u){
	
	U[u]=1;
	D[u][u]=0;
	hp.push((PII){0,u});
	while(hp.size()>0){
		PII top=hp.top();
		hp.pop();
		LL T=top.first;
		int id=top.second;
		if(!V[u][id]){
			V[u][id]=1;
			for(int i=h[id];i!=-1;i=nt[i]){
				int j=to[i];
				
				if(T+w[i]<D[u][j]&&!V[u][j]){
					
					D[u][j]=T+w[i];
					hp.push((PII){D[u][j],j});
				}
			}
		}
	}
}
 
int main(){
	memset(D,0x3f,sizeof(D));
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;//先注意一下，d可能可以用来算时间复杂度，先打暴力解 （确实） 
	for(int i=1;i<=m;i++){
		scanf("%d",&v[i]);
	}
	for(int i=1;i<=n;i++){//记录每个点所有的线 
		g[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int id,t;
			scanf("%d%d",&id,&t);
			K[id].push_back((OP){i,t});
		} 
	}
	//此处构建连接矩阵 (这里有问题)
	for(int i=1;i<=m;i++){
		for(int j=0;j<K[i].size();j++){
			for(int k=0;k<K[i].size();k++){
				int x=K[i][j].id;//左端点 
				int y=K[i][k].id;//右端点 
				LL s=K[i][j].t+K[i][k].t;//长度
				g[x][y]=min(g[x][y],s);
				
			}
		}
	} 
	//构建链式前向行 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]<0x3f3f3f3f3f3f3f3f) add(i,j,g[i][j]);
		}
	} 
	
	//查询
	
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		LL ans=v[x]+v[y];
		LL cnt=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<K[x].size();i++){
			if(!U[K[x][i].id]) {
				dijkstra(K[x][i].id);
			}
			for(int j=0;j<K[y].size();j++){
				
				cnt=min(cnt,K[x][i].t+D[K[x][i].id][K[y][j].id]+K[y][j].t);
				cnt=min(cnt,K[x][i].t+g[K[x][i].id][K[y][j].id]+K[y][j].t);
				//cout<<"===="<<K[x][i].id<<"    "<<K[y][j].id<<"   "<<g[K[x][i].id][K[y][j].id]<<endl;
			}
		}
		
		printf("%lld\n",ans+cnt);
	} 
	return 0;
}
