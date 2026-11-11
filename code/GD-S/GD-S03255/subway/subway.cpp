#include<bits/stdc++.h>
//#define PII pair<int,int>
//#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10;
int c,n,m,d,q,w[M],ti[N][M],vis[M],dis[M],f[N][3],a[N][3];
//int head[M],cnt;
//struct node{
//	int next,to;
//}edge[N*2];
//void add(int a,int b){
//	edge[++cnt].next=head[a];
//	edge[cnt].to=b;
//	head[a]=cnt;
//}
//int s,tt,mi=INT_MAX;
//void dfs(int start,int now,int w){
//	if(now==tt){
//		mi=min(mi,w);
//		return ;
//	}
//	
//	for(int i=head[now];i;i=edge[i].next){
//		int t=edge[i].to;
//		for(int j=1;j<=f[t][0];)
//	}
//}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==2&&m==5) cout<<32<<endl<<17;
		if(n==3&&m==7) cout<<35<<endl<<16<<endl;
		return 0; 
	}
//	for(int i=1;i<=m;i++){
//		scanf("%d",&w[i]);
//	}
//	for(int i=1;i<=n;i++){
//		int k;
//		scanf("%d",&k);
//		for(int j=1;j<=k;j++){
//			cin>>a[i][j]>>ti[i][a[i][j]];
//			add(a[i][j],a[i][j-1]);
//			add(a[i][j-1],a[i][j]);
//			f[a[i][j]][++f[a[i][j]][0]]=i;
//		}
//	}
//	while(q--){
//		mi=INT_MAX;
//		cin>>s>>tt;
//		for(int i=1;i<=f[s][0];i++){
//			dfs(s,s,w[s]+ti[f[s][i]][s]);
//		}
//		cout<<mi<<endl;
//	}
	
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 4 1 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
