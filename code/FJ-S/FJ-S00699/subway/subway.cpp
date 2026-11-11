#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=5e5+10;
int c,n,m,d,q,start,jieshu;
struct sta{
	int id,w,t[22];
}a[M];
bool f[1000][1000][21];
bool vis[M];
void dfs(int x){
//	vis[x]=true;
//	for(int i=1;i<=m;i++){
//		if(f[x][i]==true&&!vis[i]){
//			dfs(i);
//		}
//	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i].w);
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int x,k[505];
		scanf("%d",&x);
		for(int j=1;j<=x;j++){
			scanf("%d",&k[j]);
			scanf("%d",&a[k[j]].t[i]);
//			f[k[j]][k[j-1]]=true;
//   		f[k[j-1]][k[j]]=true;
		}
	}
	while(q--){
		scanf("%d%d",&start,&jieshu);
		dfs(start);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}