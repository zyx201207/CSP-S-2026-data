#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],vis[300001],sum[300001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)vis[j]=0;
		int cnt=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=vis[a[j]]+1;k<cnt;k++){
					vis[b[k]]=0;
				}
				cnt=vis[a[j]]+1;
			}else{
				b[cnt]=a[j];
				vis[a[j]]=cnt;
				cnt++;
			}
		}
		for(int j=1;j<=m;j++){
			sum[j]+=(bool)vis[j];
			//cout<<(bool)vis[j]<<" ";
		}//cout<<"\n";
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
} 
