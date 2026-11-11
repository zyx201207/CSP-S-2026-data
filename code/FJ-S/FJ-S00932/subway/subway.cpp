#include<bits/stdc++.h>
#define N 505
#define M 2000000
typedef long long i64;
using P=std::pair<i64,int>;
std::vector<P>g[M+N];i64 d[M];
void sd(int s)
{
	std::priority_queue<P,std::vector<P>,std::greater<P>>q;
	memset(d,0x3f,sizeof d);
	d[s]=0,q.push({0,s});
	while(!q.empty())
	{
		int tu,tv;i64 td,tw;
		std::tie(td,tu)=q.top();q.pop();
		if(td>d[tu])continue;
		for(P i:g[tu])
		{
			std::tie(tv,tw)=i;
			if(d[tv]>d[tu]+tw)
			{
				d[tv]=d[tu]+tw;
				q.push({d[tv],tv});
			}
		}
	}
}
int n,m,q,w[M];
i64 ds[N][N];
int main(void)
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d%d%d%*d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
		scanf("%d",w+i);
	for(int i=1;i<=n;++i)
	{
		int k,a,t;//Project KAT!!!
		scanf("%d",&k);
		for(int j=1;j<=k;++j)
		{
			scanf("%d%d",&a,&t);
			g[a].push_back({m+i,(i64)t});
			g[m+i].push_back({a,(i64)t});		
		}
	}
	for(int i=1;i<=n;++i)
	{
		sd(m+i);
		for(int j=1;j<=n;++j)
			ds[i][j]=d[m+j];
	}
	for(int i=1;i<=q;++i)
	{
 		int s,t;i64 r=0x3ffffffffffffff;
		scanf("%d%d",&s,&t);
		for(P u:g[s])for(P v:g[t])
			r=std::min(r,ds[u.first-m][v.first-m]+u.second+v.second);
		printf("%lld\n",w[s]+w[t]+r);
	}	
	return 0;	
}
/*简单最短路，考虑建图。
首先，考虑最外部的代表外界(目标)的m个节点,编号1~m 
向站台编号m+1~2m连权值为w[i]的无向边
其次，考虑站台作为节点，经过权值为t[i]到达该线路的乘车点
为了简化，不需要节省空间，节点度数最大为d。
我是乐乐！不编号，直接计数！！ 反正该连的边都连了！！b为当前可用的节点编号。 
2m+b就是编号 
60min了，我是乐乐 ，线路不算时间，直接第i条线路为节点2m+i就好。 
对每一条线路拆成经过它的线路个数点,这些点被线路链接  
接下来是dij板子 
fuck!超时。这需要改进。也许可以尝试记忆化？然而M^2不可能。我选择先提交第一个版本。
算法需要改进。我的算法复杂度是O(q mlogm)
我想要发掘一些图的性质。
我先开T3。我放弃T3。
我们需要O(1)查询， 这好像是树，这意味着我可以通过LCA与树上前缀和解决它？ 
这不是树，是二分图。
我只需要求每一个点到每一条线最短时间，
空间是nm的。5e2*5e5=3e8个i64绝对过不了。
让我开极限点。。这有爆0风险，，我先试T3.  
我要AFO了，再见了OI!!!!
第七点30s，rp++，祝CCF评测机跑快30x。 
*/
