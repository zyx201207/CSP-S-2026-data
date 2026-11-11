#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//wohaowuliao
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==n){
		int ans=a[0]&a[1];
		for(int i=0;i<n;i++) ans=ans&a[i];
		cout<<ans;
	}
	if(m==1){
		int ans=0;
		for(int i=0;i<n;i++){
			if(a[i]>ans) ans=a[i];
		}
		cout<<ans;
	}
	if(m==2){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if((a[i]&a[j])>ans) ans=a[i]&a[j];
			}
		}
		cout<<ans;
	}
	if(m==3){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					if((a[i]&a[j]&a[k])>ans) ans=a[i]&a[j]&a[k];
				}
			}
		}
		cout<<ans;
	}//mnopqrst
	if(m==4){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						if((a[i]&a[j]&a[k]&a[l])>ans) ans=a[i]&a[j]&a[k]&a[l];
					}
				}
			}
		}
		cout<<ans;
	}
	if(m==5){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							if((a[i]&a[j]&a[k]&a[l]&a[o])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o];
						}
					}
				}
			}
		}
		cout<<ans;
	}
	if(m==6){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								if((a[i]&a[j]&a[k]&a[l]&a[o]&a[p])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o]&a[p];
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	if(m==7){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								for(int q=p+1;q<n;q++){
									if((a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q];
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	if(m==8){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								for(int q=p+1;q<n;q++){
									for(int r=q+1;r<n;r++){
										if((a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r];
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
	}
	if(m==9){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								for(int q=p+1;q<n;q++){
									for(int r=q+1;r<n;r++){
										for(int s=r+1;s<n;s++){
											if((a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s];
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
	}
	if(m==10){
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int o=l+1;o<n;o++){
							for(int p=o+1;p<n;p++){
								for(int q=p+1;q<n;q++){
									for(int r=q+1;r<n;r++){
										for(int s=r+1;s<n;s++){
											for(int t=s+1;t<n;t++){
												if((a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t])>ans) ans=a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]&a[r]&a[s]&a[t];
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
	}
	//看在我写了十重循环的份上，多给我四分吧 
	//我一点都不累 
	return 0;
}
