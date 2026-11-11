#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int mapp[20005][20005];
node w[500005],book[500005];
int cc,n,m,dd,qq;
int dfs(int ccc,int xian,int shu){
	book[xian]=1;
	
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>cc>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i].x;
	}
	for(int i=1;i<=n;i++){
		int v;
		cin>>v;
		int aa,bb;
		for(int i=1;i<=v;i++){
			cin>>aa>>w[i].y;
			mapp[aa][bb]=1;
			mapp[bb][aa]=1;
			bb=aa;
		}
	}
	for(int i=1;i<=qq;i++){
		int chu,dao;
		cin>>chu>>dao;
		dfs(chu,chu,0);
	}
	return 0;
}

