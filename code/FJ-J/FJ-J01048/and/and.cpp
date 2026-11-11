#include <bits/stdc++.h>
using namespace std;
int n,m,p;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxa=-999,maxn=-999;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(m==1){
		cout<<maxa<<'\n';
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxn=max(maxn,(a[i]&a[j])&a[k]);
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxn=max(maxn,(a[i]&a[j])&(a[k]&a[l]));
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							maxn=max(maxn,(a[i]&a[j])&(a[k]&a[l])&a[o]);
						}
					}
				}
			}
		}
	}
	else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								maxn=max(maxn,(a[i]&a[j])&(a[k]&a[l])&(a[o]&a[p]));
							}
						}
					}
				}
			}
		}
	}
	else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									maxn=max(maxn,(a[i]&a[j])&(a[k]&a[l])&(a[o]&a[p])&a[q]);
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int o=l+1;o<=n;o++){
							for(int p=o+1;p<=n;p++){
								for(int q=p+1;q<=n;q++){
									for(int r=q+1;r<=n;r++){
										maxn=max(maxn,(a[i]&a[j])&(a[k]&a[l])&(a[o]&a[p])&(a[q]&a[r]));
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
