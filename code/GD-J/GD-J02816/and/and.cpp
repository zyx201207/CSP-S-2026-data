#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+101;
int n,m,a[N],b[N],vis[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int mx=a[i];
		vis[i]=1;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<m;j++){
			int y=0,yid=0;
			for(int k=1;k<=n;k++){
				if(i!=k&&vis[k]==0){
					y=a[k];
					yid=k;
					break;
				}
			}
			for(int k=1;k<=n;k++){
				if(i==k||vis[k]==1)continue;
				if(mx&a[k]>mx&y){
					y=a[k];
					yid=k;
				}
			}
			mx=mx&y;
			vis[yid]=1;
		}
		ans=max(mx,ans);
	}
	cout<<ans;
	return 0;
} 
