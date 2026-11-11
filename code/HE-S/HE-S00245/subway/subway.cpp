#include<bits/stdc++.h>
using namespace std;

int c,m,n,d,q;
int w[500005],k[550],a[550][50000],t[550][50000],x,y;
int ans;
int ed[550][500050],l[550];
void bfs(int ww,int aa){
	aa+=w[ww];
	if(ww==y){
		ans=min(ans,aa);
		return;
	}
	for(int i = 1;i <= l[ww];i++){
		bfs(ed[ww][i],aa+t[1][1]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(l,0,sizeof(l));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&k[i]);
		for(int j = 1;j <= k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			
			
		}
		
		for(int j = 1;j<k[i];j++){
			for(int p = j+1;p <= k[i];p++){
				ed[a[n][j]][++l[a[n][j]]]=a[n][p];
				ed[a[n][p]][++l[a[x][p]]]=a[n][j];
			}
		}
	}
	for(int i = 1;i <= q;i++){
		scanf("%d%d",&x,&y);
		ans=1e9+10;
		bfs(x,0);
		printf("%d\n",ans);
		
	}
	return 0;
}

