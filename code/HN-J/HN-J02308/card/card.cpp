#include<bits/stdc++.h>;
using namespace std;;
int main(){
	int n,m,a[500005],ss=0,sum[300005]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int z=1;z<=n;z++){
		bool vis[500005]={1},hs[300005]={0};
		for(int i=z;i<=n;i++){
			if(hs[a[i]]==1){
				for(int j=i;j<=i;j++){
					vis[j]=0;
				}
				hs[i]=0;
			}
			else{
				hs[a[i]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]){
				sum[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i];
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
} 
