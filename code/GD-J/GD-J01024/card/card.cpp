#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005];
int front[500005],on[500005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		on[i]=front[a[i]];
		front[a[i]]=i;
	}
//	for(int i=1;i<=n;i++) cout<<on[i]<<" ";
//	cout<<"\n";
	if(n<=500){
		bool vis[505];
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(a[j]==a[k]&&vis[k]==0){
						for(int l=k;l<=j-1;l++){
							vis[l]=1;
						}
						break;
					}
				}
			}
			for(int j=i;j<=n;j++){
				if(vis[j]==0) ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}
	else if(n<=5000){
		bool vis[5005];
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			for(int j=i;j<=n;j++){
				if(on[j]>=i&&vis[on[j]]==0){
					for(int k=on[j];k<=j-1;k++) vis[k]=1;
				}
//				for(int i=1;i<=n;i++){
//					cout<<vis[i]<<" ";
//				}
//				cout<<"\n";
			}
			for(int j=i;j<=n;j++){
				if(vis[j]==0){
					ans[a[j]]++;
				}
			}
//			cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
}

