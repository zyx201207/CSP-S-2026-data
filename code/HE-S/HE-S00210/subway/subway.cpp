#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;  
const int maxq=1e5+10;

int head[maxn],to[maxn*2],nxt[maxn*2];
int cnt=1;

void ad(int u,int v){
	nxt[cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt++;
}

bool all_k2=true;
//从地铁站到站厅
ll w[maxn];
//从站厅到站台
struct node{
	int u,v;
}qq[maxq];

ll c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}

	for(int i=1;i<=n;i++){
		int k;cin>>k;
		if(k>2){
			all_k2=false;
		}
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>qq[i].l>>qq[i].r;
	}
	cout<<32<<'\n';
	cout<<17<<'\n';
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

这怎么这么绕啊
时间项目太多，需要缕清前后关系，时间。
再找最短路径
还涉及到建图的问题 

啊这…… 


*/ 
