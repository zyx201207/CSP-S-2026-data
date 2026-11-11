#include<bits/stdc++.h>
using namespace std;
int a[200005];//,ans[200005]
//void dfs(int pos){
//	if(pos=n+1){
////		cout<<ans<<endl;
//		return;
//	}
//	for()
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				else{
					int x=a[i],y=a[j];
					int new_ans=(x&y);
					ans=max(ans,new_ans);
				}
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					if(i==j||j==l||i==l){
						continue;
					}
					else{
						int x=a[i],y=a[j],z=a[l];
						int new_ans=(x&y&z);
						ans=max(ans,new_ans);
					}
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					for(int o=1;o<=n;o++){
						if(i==j||j==l||i==l||i==o||j==o||l==o){
							continue;
						}
						else{
							int x=a[i],y=a[j],z=a[l],z1=a[o];
							int new_ans=(x&y&z&z1);
							ans=max(ans,new_ans);
						}
					}
				}
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					for(int o=1;o<=n;o++){
						for(int p=1;i<=n;i++){
							if(i==j||j==l||i==l||i==o||j==o||l==o||p==i||j==p||o==p||l==p){
								continue;
							}
							else{
								int x=a[i],y=a[j],z=a[l],z1=a[o],z2=a[p];
								int new_ans=(x&y&z&z1&z2);
								ans=max(ans,new_ans);
							}
						}
					}
				}
			}
		}
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int l=1;l<=n;l++){
					for(int o=1;o<=n;o++){
						for(int p=1;i<=n;i++){
							for(int q=1;i<=n;i++){
								if(i==j||j==l||i==l||i==o||j==o||l==o||p==i||j==p||o==p||l==p||i==q||j==q||l==q||o==q||q==p){
									continue;
								}
								else{
									int x=a[i],y=a[j],z=a[l],z1=a[o],z2=a[p],z3=a[q];
									int new_ans=(x&y&z&z1&z2&z3);
									ans=max(ans,new_ans);
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<ans;
//	int x;
//	x=(12&12);
//	cout<<x<<endl;
	return 0;
}
