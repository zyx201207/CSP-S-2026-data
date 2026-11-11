#include<bits/stdc++.h>
using namespace std;
long long kmp[405][405],c,n,m,d,q,w[405],kk[405],a[405],ww,tong[405][405],mp[405][405],v[205][405];
long long line[405][405],sum[405],t[405][405];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			v[i][j]=131452013697891;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[i][j]=131452013697891;
			if(i==j){
				mp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&kk[i]);
		for(int j=1;j<=kk[i];j++){
			scanf("%lld%lld",&a[j],&ww);
			tong[i][a[j]]=1;
			v[i][a[j]]=ww;
			line[a[j]][++sum[a[j]]]=i;
		}
		for(int j=1;j<=kk[i];j++){
			for(int k=1;k<=kk[i];k++){
				kmp[a[j]][a[k]]=1;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){	
				if(tong[i][k]&&tong[j][k]){
					mp[i][j]=min(mp[i][j],v[i][k]+v[j][k]);
				}
			} 
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){	
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
			} 
		}
	}
	int x,y;
	while(q--){
		long long ans=131452013697891;
		cin>>x>>y;
		for(int i=1;i<=sum[x];i++){
			for(int j=1;j<=sum[y];j++){
				ans=min(ans,mp[line[x][i]][line[y][j]]+w[x]+w[y]+v[line[x][i]][x]+v[line[y][j]][y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
