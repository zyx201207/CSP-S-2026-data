#include<bits/stdc++.h>
using namespace std;
int n,d,is[3005],g[3005][3005];
bool ans[3005][3005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int fin=0;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			is[i]=0;
			for(int j=0;j<n;j++){
				g[i][j]=-1;
				ans[i][j]=0;
			}
		} 
		for(int i=0;i<n;i++){
			cin>>is[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(abs(is[i]-is[j]))g[i][j]=1;
			} 
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(g[i][k]!=-1&&g[k][j]!=-1){
						if(g[i][j]==-1||(g[i][k]+g[k][j]>g[i][j])){
							g[i][j]=g[i][k]+g[k][j];
						}
						else if(g[i][j]==g[i][k]+g[k][j])ans[i][j]=1;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]==1){
					fin++;
				}
			}
		}
		cout<<fin/2;
	}
	return 0;
}
