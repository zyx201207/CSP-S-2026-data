#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=5e5+10;
int n,m,c,d,q;
int w[M],k[M];
int a[N][M];
int a1[N][M];
int t[N][M];
bool vis[M];
struct std{
	int to[N];
}turning[M];
int countstd[M];
struct std1{
	int turnnum[M];
}line[N];
long long ans=1e9+7;
//void dfs(long long time,int des,int num,int at){
//	if(num==des){
//		ans=min(ans,time);
//		return;
//	}
//	vis[num]=1;
//	for(int j=1;line[at].turnnum[j]!=0;j++){
//		if(!vis[line[at].turnnum[j]]&&countstd[line[at].turnnum[j]]>1){
//			vis[line[at].turnnum[j]]=1;
//			dfs(time+t[turning[line[at].turnnum[j]].to[i]][a1[at][line[at]]])
//		}
//	}
//}WO LEI LE QWQ
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		int gg=0;
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			a1[i][a[i][j]]=j;
			turning[a[i][j]].to[countstd[a[i][j]]++]=i;
			line[i].turnnum[++gg]=a[i][j];
		}
	}
	while(q--){
		int x,y;
		bool ttt=1;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			if(a1[i][x]&&a1[i][y]){
				cout<<w[x]+w[y]+t[i][a1[i][x]]+t[i][a1[i][y]]<<"\n";
				t=0;
				break;
			}
		}
		if(ttt)dfs(w[x]+w[y],y,x,turning[x].to[1]);
	}
	return 0;
}

