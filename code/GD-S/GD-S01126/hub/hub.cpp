#include<bits/stdc++.h>
#define int long long
#define I return
#define LOVE 0
#define CCF ; 
using namespace std;
const int N=1000005;
int c,T,n,k,f,t,h[N],fa[N],lca[N][25];
vector<int>a[N];
void dfs(int heigh,int father,int node){
	h[node]=heigh;
	fa[node]=father;
	for(auto i:a[node]){
		if(father==i)continue;
		dfs(heigh+1,node,i);
	}
}
void ddfs(int node){
	lca[node][0]=fa[node];
	for(int i=1;i<=20;i++)
	{
		lca[node][i]=lca[lca[node][i-1]][i-1];
	}
}
int find(int x,int y){
	if(h[x]<h[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(h[x]+pow(2,i)<=h[y])x=lca[x][i];
	}
	for(int i=20;i>=0;i--){
		if(lca[x][i]!=lca[y][i])x=lca[x][i],y=lca[y][i];
	}
	return fa[x];
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f>>t;
		a[f].push_back(t);
	}
	dfs(1,0,1);
	ddfs(1);
	vector<int>ans;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int lc=find(i,j);
			ans.push_back(abs(h[lc]-h[i])+abs(h[lc]-h[j]));
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-k+1]<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)solve();
    I LOVE CCF
    I LOVE CCF
    I LOVE CCF//重要的事情说三遍
	int rp;
	while(1)rp++; 
}
/*
还有14分钟，短短写一篇游记吧
2：10 进考场
2：28 打开试卷，一眼便看懂了T1的做法
4：18 感谢CCF给的题，我竟然把T1做对了！
4：31 想了半天解不开T2果断的打下了暴力 
4:41  打完T2暴力
5：02 DEV-C++神力，T3成功做到输入RE
 5：20 终于搞好T3输入RE的问题了，我真是太难了，呜呜呜 
 5：40 T3暴力终于写完了，我要崩了
 5：50 T4啥玩意看不懂，写个LCA庆祝一下吧
 6：06 T4RE我也不管了好吧，摸鱼ING... 
*/ 

