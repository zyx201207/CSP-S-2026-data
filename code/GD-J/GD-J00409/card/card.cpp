#include<bits/stdc++.h>
using namespace std;
int n,m,f[500010],g[500010],k[500010],sum[500010],p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		fill(k+1,k+1+n,0),fill(g+1,g+1+n,0);
		for(int j=i;j<=n;j++){
			//cout<<g[f[j]]<<" "<<k[g[f[j]]];
			if(g[f[j]]&&k[g[f[j]]]==0){//cout<<"'";
				for(int l=g[f[j]];l<j;l++){
					while(k[l]!=0){
						l=k[l];
					}
					if(l<j)k[l]=j;
				}
				g[f[j]]=j,k[j]=0;
			}
			else g[f[j]]=j,k[j]=0;
			//cout<<"\n";
		}
		for(int j=i;j<=n;j++){
			if(k[j]==0) sum[f[j]]++;
			//cout<<k[j]<<" "<<f[j]<<" "<<sum[f[j]]<<"\n";
		}//cout<<"¡¢\n"; 
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	return 0;
}
