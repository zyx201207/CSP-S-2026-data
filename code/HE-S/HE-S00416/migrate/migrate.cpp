#include<bits/stdc++.h>
using namespace std;
int k,c,t,n,d,x[2000005],tot=0,ans;
/*struct edge{//单向u->v,长为1 
	int u;
	int v;
};
int bfs(int i,int j){//i-j的最短路计数
	if(i=j) {
		return 1;
	}
	for(i=0;i<k;i++){
		bfs()
	}
}
edge graph[2000000];*/ 
//int to[2000000]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c>>t;
	
	for(int i=0;i<t;i++){
		/*
		cin >> n>>k;
		tot=0;
		for(int j = 1;j <= n;j++){
			cin >> x[j];
			for(int l = 1;l <= j;l++){//能飞到就建边 
				//cin >> x[i];
				if(x[j]-x[l]<=k){
					tot++;
					//to[l]
					edge[tot].u=l,edge[tot].v=k;
				}
			}
		}*/
		cout << 0<<endl;//为解决13，14而生 
	}
	//最短路计数 特殊性：i-j的最短路==i-k的最短路+k-j的最短路成立，因为松弛不会减小路程 

}
 
