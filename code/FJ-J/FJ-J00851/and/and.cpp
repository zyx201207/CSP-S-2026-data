#include <bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,ans^a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m>20){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						ans=max(ans,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]);
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]);
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int z=y+1;z<=n;z++){
									ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[z]);
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int z=y+1;z<=n;z++){
									for(int b=z+1;b<=n;b++){
										ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[z]&a[b]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int z=y+1;z<=n;z++){
									for(int b=z+1;b<=n;b++){
										for(int c=b+1;c<=n;c++){
											ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[z]&a[b]&a[c]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int x=l+1;x<=n;x++){
							for(int y=x+1;y<=n;y++){
								for(int z=y+1;z<=n;z++){
									for(int b=z+1;b<=n;b++){
										for(int c=b+1;c<=n;c++){
											for(int d=c+1;d<=n;d++){
												ans=max(ans,a[i]&a[j]&a[k]&a[l]&a[x]&a[y]&a[z]&a[b]&a[c]&a[d]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
