#include<bits/stdc++.h>//对于1-9测试点n<=500 m<=1000 
using namespace std;
int c,n,m,d,q,k;
int w[1005],top[1005];
int xb[1005][1005];
int a[505][1005];
int aij,tij,x,y,mi;
int top2[1005];
long long ans;
//c是滚木，n地铁线路数、
//m地铁站数、d每个地铁站最多被几条线路经过(滚木)，q以及出行计划数 
//k是第n个线路经过地铁站个数
void dfs(int qidian,int shijian){
	for(int l=1;l<=n;l++){
		if(a[l][qidian]!=0&&a[l][w[y]]!=0){
			mi=min(mi,shijian+a[l][qidian]+a[l][w[y]]);
			return ;
		}	
	}
	if(top[qidian]==1) return ;
	for(int l=1;l<=top[qidian];l++){//线路 
		for(int l1=1;l1<=m;l1++){//地铁站 
			if(a[l][l1]!=0) {
				top[qidian]++;
				dfs(l1,shijian+a[l][l1]);
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>aij>>tij;
			a[i][aij]=tij;
			xb[i][++top[aij]]=i;
		}
		//xb[i][j]表示第i个地铁站有的第j个站厅(线路)编号  为for循环中指的i  
		//a[i][j]表示第i条线路站厅到其第j个地铁站所需时间 
		//aij表示第 i 条线路经过的第 j个地铁站
		//tij表示从该地铁站的站厅 i条线路的站台需要行走的时间
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=w[x]+w[y];
		mi=1e8;
		dfs(w[x],0);
		for(int j=1;j<=m;j++) top2[j]=0;
		cout<<ans+mi<<endl;
	}
	return 0;
	
}
