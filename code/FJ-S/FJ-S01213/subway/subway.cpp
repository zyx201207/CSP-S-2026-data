#include<bits/stdc++.h>
using namespace std;
const int N=505,M=1e5*5+5;
int c,n,m,d,q;
int k[N],a[N][M],t[N][M],w[M],l[M][21],o[M];
int x,y;
int dp[M];
int ans;
void dfs(int pos){
	for(int i=1;i<=o[pos];i++){
		ans+=
		for(int j=1;j<=k[l[pos][i]];j++){
			if(a[i][j]!=pos){
				ans+=t[i][j];
				dfs(a[i][j]);
				ans-=t[i][j];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			o[a[i][j]]++;
			l[a[i][j]][o[a[i][j]]]++;
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
	}
	if(c>=7&&c<=11){
		for(int e=1;e<=q;e++){
			scanf("%d %d",&x,&y);
			ans=w[x]+w[y];
		}
	}
	return 0;
}