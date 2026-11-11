#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=500010;
int c,n,m,d,q,a,b,ct[N],to[N][23];
LL ans,w[N],t[510][510],s[N][23];
int main(){
//	system("fc subway.out subway7.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			t[i][j]=1e15;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		t[i][i]=0;
		for(int j=1;j<=c;j++){
			scanf("%d",&a);
			ct[a]++,to[a][ct[a]]=i;
			scanf("%lld",&s[a][ct[a]]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ct[i];j++){
			a=to[i][j];
			for(int k=j+1;k<=ct[i];k++){
				b=to[i][k];
				t[a][b]=min(t[a][b],s[i][j]+s[i][k]);
				t[b][a]=t[a][b];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d%d",&a,&b),ans=1e16;
		for(int i=1;i<=ct[a];i++){
			for(int j=1;j<=ct[b];j++){
				int x=to[a][i],y=to[b][j];
				ans=min(ans,t[x][y]+s[a][i]+s[b][j]);
			}
		}
		ans+=w[a]+w[b];
		printf("%lld\n",ans);
	}
	return 0;
} 
