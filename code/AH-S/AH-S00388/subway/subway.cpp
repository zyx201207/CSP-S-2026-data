#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
int c,n,m,d,q,k[510];
int t1,x,y,t2;
using namespace std;
int w[500010];
ll f[1010][1010];
int subway[510][500010];
vector <int> stat[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	c=12;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&t1,&t2);
			subway[i][t1]=t2;
			stat[t1].push_back(i);
		}
	}
	if(c==21||c==20){
		ll sum=1e18,temp=1e18;
		for(int i=1;i<=m;i++){
			if(subway[1][i]&&subway[2][i]){
				sum=min(sum,(long long)subway[1][i]+subway[2][i]);
			}
		}
		while(q--){
			scanf("%d %d",&x,&y);
			temp=1e18;
			if(subway[1][x]&&subway[1][y]) temp=min(temp,(long long)subway[1][x]+subway[1][y]);
			if(subway[2][x]&&subway[2][y]) temp=min(temp,(long long)subway[2][x]+subway[2][y]);
			if(subway[1][x]&&subway[2][y]) temp=min(temp,(long long)subway[1][x]+temp+subway[2][y]);
			if(subway[2][x]&&subway[1][y]) temp=min(temp,(long long)subway[2][x]+temp+subway[1][y]);
			printf("%lld\n",temp+w[x]+w[y]);
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(c>=12){
		ll temp=1e18;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					f[i][j]=0;
				}
				else f[i][j]=1e18;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=0;j<stat[i].size();j++){
				for(int k=0;k<stat[i].size();k++){
					f[stat[i][j]][stat[i][k]]=min(f[stat[i][j]][stat[i][k]],(long long)subway[stat[i][j]][i]+subway[stat[i][k]][i]);
				}
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		while(q--){
			scanf("%d %d",&x,&y);
			temp=1e18;
			
			for(int i=0;i<stat[x].size();i++){
				for(int j=0;j<stat[y].size();j++){
					temp=min(temp,f[stat[x][i]][stat[y][j]]+subway[stat[x][i]][x]+subway[stat[y][j]][y]);
				}
			}
			printf("%lld\n",temp+w[x]+w[y]);
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=m;i++){
			if(!subway[l][i]) continue;
			for(int j=1;j<=m;j++){
				if(subway[l][i]&&subway[l][j]){
					f[i][j]=min(f[i][j],(long long)subway[l][i]+subway[l][j]);
				}
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(f[i][k]==1e18) continue;
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		scanf("%d %d",&x,&y);
		printf("%lld\n",w[x]+f[x][y]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
