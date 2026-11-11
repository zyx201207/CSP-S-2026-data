#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=l;i<=(r);i++)
#define fs first 
#define sc second 
const int N=509,M=5e5+7;
using node=pair<int,int>; 
int c,n,m,d,q;
int w[M],C[N][N];
vector<node>L[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	rep(i,1,n)rep(j,1,n)C[i][j]=1e18;
	rep(i,1,n){
		C[i][i]=0;int k,u,v;cin>>k;
		rep(j,1,k)cin>>u>>v,L[u].push_back({i,v});//L[i]的大小不超过d 
	} 
	rep(i,1,m){
		int k=L[i].size();
		rep(j,0,k-1)rep(j2,j+1,k-1){
			node I=L[i][j],J=L[i][j2];
			C[J.fs][I.fs]=C[I.fs][J.fs]=min(C[I.fs][J.fs],I.sc+J.sc);
		}
	} 
	rep(k,1,n)rep(i,1,n)rep(j,1,n)
		if(i!=k and i!=j and j!=k)
			if(C[i][k]<1e18 and C[k][j]<1e18)
				C[i][j]=min(C[i][j],C[i][k]+C[k][j]);
	for(int u,v;q-- and cin>>u>>v;){
		int ans=1e18;
		for(auto i:L[u])for(auto j:L[v])
			ans=min(ans,i.sc+j.sc+C[i.fs][j.fs]);
		cout<<w[u]+w[v]+ans<<endl;
	}
	return 0;
}
/*
梳理一下题目给的条件：
1.从第x个地铁口出发，从第y个地铁口离开，固定代价为w[x]+w[y]；
2.选择初始线路和结束线路时，也要支付代价f(a,x)+f(b,y)。 
3.换乘时，两条线路a,b在交点G处，需要代价f(a,G)+f(b,G)。
询问最小化代价。注意，一个站台最多只有20条线路经过。

这看上去未免太不可做了。考虑设C[i,j]表示从第i条线路换乘到第j条线路的代价。
线路数量是少的，站台数量是多的。考虑我们建图的复杂度，实际上并不高。
那这不是蠢题吗，除非它要求必须依次经过（也就是不能在上车后向回开，但这可能吗？）
题意表意不明，该罚！ 

*/
