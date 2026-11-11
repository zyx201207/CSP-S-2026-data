#include<bits/stdc++.h>
using namespace std;
long long vis[500005],ans[500005],n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==0){
				vis[a[j]]=1;
			}
			else{
				bool f=0;
				for(int k=i;k<=j;k++){
					if(a[k]==a[j]){
						f=1;
					}
					else if(f==1){
						vis[a[k]]=0;
					}
				}
			}			
		}
		for(int j=1;j<=n;j++){
			if(vis[a[j]]==1){
				ans[a[j]]++;
				vis[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
