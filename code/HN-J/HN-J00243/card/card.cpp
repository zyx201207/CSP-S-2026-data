#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,vis[5005][3005],ans[3005],an[3005],bn[3005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>an[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[i][an[j]]>=1){
				for(int k=bn[an[j]];k<=j;k++)vis[i][an[k]]=0;
			}
			vis[i][an[j]]++;
			bn[an[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(vis[i][j]>=1)ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}


