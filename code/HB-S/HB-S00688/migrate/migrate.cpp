#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[10010],xx[5050][5050],sum,k[5050];
bool f[10010];
void dfs(int y,int s,int l){
	if(y==s){k[l]++;}
	for(int i=min(y,s);i<=max(y,s);i++){
		if(xx[i][y]<=d&&!f[i]){
			f[i]=1;
			dfs(i,s,l+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(;t--;){
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				xx[i][j]=abs(x[i]-x[j]);
				xx[j][i]=abs(x[i]-x[j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				memset(f,0,sizeof(f));
				memset(k,0,sizeof(k));
				dfs(i,j,0);
				for(int y=0;y<=n;y++){
					if(k[y]){
						if(k[y]==2){sum++;}
						break;
					}
				}
			}
		}
		cout<<sum<<'\n';
	}
	
	
	return 0;
}
