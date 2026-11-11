#include<bits/stdc++.h>
using namespace std;
long long k,w[20001],b[20001],f[15001][15001],n,m,T,ans;
long long a[20001];
void dfs(int x,int y,long long s){
	if(f[x][y]==1){
		ans=min(ans,s);
		return ;
	}b[x]=1;
	for(int i=1;i<=m;i++){
		if(b[i]==0 and f[x][i]==1){
			dfs(i,y,s+1);
		}
	}b[x]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>T;
			
		}for(int j=2;j<=n;j++){
			f[a[j-1]][a[j]]=1;
		}
	}int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;ans=(1<<30);
		dfs(x,y,1);
		cout<<w[x]+w[y]+ans*2*T<<endl;
	}
	return 0;
} 
