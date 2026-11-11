#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500001],k[501];
int a[501][20001],t[501][20001];
struct node{
	int vi,num;
	const bool operator < (const node &rhs) const{
		return this->vi < rhs.vi;
	}
};
int dij(int x,int y){
	queue <node> q;
	node sd;
	sd.vi=0,sd.num=x;
	q.push(sd);
	while(!q.empty()){
		node tp=q.front();
		q.pop();
		if(tp.num==y){
			return tp.vi;
		}
		for(int v=1;v<=k[tp.num];v++){
			if((tp.num==x)||(tp.num==y)){
				q.push({t[tp.num][a[tp.num][v]]+tp.vi,a[tp.num][v]});
				continue;
			}
			q.push({t[tp.num][a[tp.num][v]]+t[a[tp.num][v]][a[tp.num][v]]+tp.vi,a[tp.num][v]});
		}
	}
}
int main(){
	//路线：地铁口->站厅->站台->站厅->地铁口
	//理解题目用了40min
	//西西弗斯十分易怒
	//他明知每次推石头都不成功，而这也是他咎由自取
	//(指我每道题都做不出来) 
	//但他还是怒骂这些石头，不允许石头忤逆他
	//他认为石头没有思想，没有力量
	//(指题面有点复杂，解释不清)
	//但我认为，西西弗斯的苦难终会结束，石头也将得以休息 
	//(指我看不懂题目很生气，并非题外话)
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,u,v;j<=k[i];j++){
			cin>>u>>v;
			a[i][j]=u;//i号线经过的第j个地铁站是u
			t[i][j]=v;//从i号线第j个站走回i号线站厅的时间 
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y]+t[x][x];
		//a[i][k]=j 
		//从i号站厅到j号站台用时t[i][k]+
		//从 i 
		cout<<ans+dij(x,y)<<endl;
	}
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
