#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+5,M=1e3+5,inf=1e18+5;
int c,n,m,d,q,cnt,f[M][M],su[N];
inline void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)f[i][j]=inf;
	for(int i=1;i<=n;i++)f[i][i]=0;
}
struct node{int idx,value;};
vector<node> vt[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;init();
	for(int i=1;i<=m;i++)cin>>su[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,v;j<=k;j++)
			cin>>u>>v,vt[u].push_back({i,v});
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vt[i].size();j++){
			for(int k=j+1;k<vt[i].size();k++){
				int t=vt[i][j].idx;
				int t2=vt[i][k].idx;
				f[t][t2]=f[t2][t]=min(f[t][t2],vt[i][j].value+vt[i][k].value);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(f[i][k]==inf)continue;
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		int res=inf;
		for(int j=0;j<vt[u].size();j++){
			for(int k=0;k<vt[v].size();k++){
				int t=vt[u][j].idx;
				int t2=vt[v][k].idx;
				res=min(res,f[t][t2]+vt[u][j].value+vt[v][k].value);
			}	
		}
		cout<<res+su[u]+su[v]<<endl;
	}
	return 0;
}
/*
"C://Users//admin//Desktop//test.in.txt"
"C://Users//admin//Desktop//test.out.txt"
fc "C:\Users\admin\Desktop\test.out.txt" "C:\Users\admin\Desktop\test.ans.txt"	
开t2 
不难发现这是一个极为稠密的图，因此我们可以考虑使用floyed
想一想，可以将一个站拆成展厅和线路上的站点两个点
然后n来到了1000，floyed应该是可以跑的
来试一下 
不对,有问题, 好像一个站 不只会被拆成2个点，怎么办呢
好吧发现一个事情，在n<=500的情况下其实没必要拆成多个点
直接暴力连边，反正最多也就250000条，唯一的问题是我们建边的过程十分麻烦
怎么做? 
根号分治！！！！
对于一条线路上有超过 sqrt(5e5)个点的路线，我们直接建成虚点
否则我们暴力连边
分析一下复杂度，我们加点肯定是没有什么问题的
应该来说暴力建边 也没什么问题
那么就会有1200来个点， 最多3e8多条边
感觉跑floyed还是太极限了啊
我们调整一下块长？或者干脆把多建点少建边当作目标？
不对我们好像理解错题意了，好像n是线路数，m才是点数
那我们直接把一条地铁线路建成一个虚点
那么边数应该就是1e6吧 
考虑一下这个比较神秘的性质，一个点至多被20条铁路线通过
然后我们还有一个性质就是我们这样建成的图中只存在虚点和实点的边
而虚点只有五百个
嗯？是不是可以求出任意虚点之间的距离？
拥有20条边的实点至多有2.5e5个
乘上400就是1e8
加上floyed的1.25e8
加上询问时枚举的4e7
加上CCF评测机极致的速度
大概是能过的！！！
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

AC了！！！ 
热泪盈眶一波！！！
活着！！！！ 
*/
