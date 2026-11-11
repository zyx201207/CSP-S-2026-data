#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],vis[5005][5005],p[5005][3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			vis[i][j]=1;
			if(p[j][a[i]]){
				for(int k=p[j][a[i]];k<i;k++){
					if(vis[k][j]){
						vis[k][j]=0;
						p[j][a[k]]=0;
					}
				}
			}
			p[j][a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=n;j++){
			if(p[j][i]){
				ans++;
			}
		}
		cout<<ans<<' ';
	}
	return 0;
}
