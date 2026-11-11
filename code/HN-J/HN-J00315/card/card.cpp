#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010],v[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){ 
				if(a[k]==j&&v[j]==0){
					v[j]=1;
					ans[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i==m/2+1) ans[i]--;
		cout<<ans[i]<<' '; 
	}
	return 0;
}
