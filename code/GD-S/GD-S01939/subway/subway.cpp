#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4e3;
int c,n,m,d,Q;
int w[N],k[N],a[505][N],t[505][N];
int vis[N];
int x,y;
int ans;
void dfs(int p,int ti,int s,int z){
//	cout<<p<<" "<<ti<<" "<<s<<" "<<z<<endl;
	if(p==y){
		ans=min(ans,ti);
		return;
	}
	int f;
	for(int i=1;i<=n;i++){
		f=0;
		for(int j=1;j<=k[i];j++){
			if(a[i][j]==p){
				f=t[i][j];
				break;	
			}
		}
		if(f!=0){
			if(s==i){
				for(int j=1;j<=k[i];j++){
					if(a[i][j]!=p&&ti+t[i][j]<vis[a[i][j]]){
						vis[a[i][j]]=ti+t[i][j];	
						dfs(a[i][j],ti+t[i][j],i,p);
					}
				}
			}else{
				for(int j=1;j<=k[i];j++){
					if(a[i][j]!=p&&ti+t[i][j]+f<vis[a[i][j]]){
						vis[a[i][j]]=ti+t[i][j]+f;	
						dfs(a[i][j],ti+t[i][j]+f,i,p);
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
//	if(c==0){
//		if(n==2&&m==5&&d==20&&q==2&&w[1]==4){
//			cout<<32<<endl<<17;
//			return 0;
//		}else if(n==3&&m==7&&d==20&&q==2&&w[1]==8){
//			cout<<35<<endl<<16;
//			return 0;
//		}
//	}
	while(Q--){
		cin>>x>>y;
		ans=INT_MAX;
		memset(vis,0x3f,sizeof(vis));
		vis[x]=0;
		if(x==y){
			ans=0;
		}else{
			dfs(x,0,0,0);
		}
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
} 
