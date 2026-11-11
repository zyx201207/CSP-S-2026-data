#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn,ans;
void dfs(int i,int h,int ans){
	if(h==m){
		for(int j=i+1;j<=n;j++){	
			int p=ans&a[j];
			maxn=max(maxn,p);
		}
		return;
	}
	for(int j=i+1;j<=n;j++){
		dfs(j,h+1,ans&a[j]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)ans=a[i];
		else{
			ans&=a[i];
		}
		maxn=max(maxn,a[i]);
	}
	if(m==1) {
		cout<<maxn;
		return 0;
	}
	maxn=0;
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3){
		for(int i=1;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				for(int l=j+1;l<=n;l++){
					maxn=max(maxn,a[i]&a[j]&a[l]);				
				}

			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==4){
		for(int i=1;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int l=j+1;l<n;l++){
					for(int u=l+1;u<=n;u++){
						maxn=max(maxn,a[i]&a[j]&a[l]&a[u]);					
					}
				
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==5){
		for(int i=1;i<n-3;i++){
			for(int j=i+1;j<n-2;j++){
				for(int l=j+1;l<n-1;l++){
					for(int u=l+1;u<n;u++){
						for(int k=u+1;u<=n;u++){
							maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]);							
						}
				
					}
				
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==6){
		for(int i=1;i<n-4;i++){
			for(int j=i+1;j<n-3;j++){
				for(int l=j+1;l<n-2;l++){
					for(int u=l+1;u<n-1;u++){
						for(int k=u+1;u<n;u++){
							for(int op=k+1;op<=n;op++){
								maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]&a[op]);						
							}
								
						}
				
					}
				
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==7){
		for(int i=1;i<n-5;i++){
			for(int j=i+1;j<n-4;j++){
				for(int l=j+1;l<n-3;l++){
					for(int u=l+1;u<n-2;u++){
						for(int k=u+1;u<n-1;u++){
							for(int op=k+1;op<n;op++){
								for(int oi=op+1;oi<=n;oi++){
									maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]&a[op]&a[oi]);								
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
	if(m==8){
		for(int i=1;i<n-6;i++){
			for(int j=i+1;j<n-5;j++){
				for(int l=j+1;l<n-4;l++){
					for(int u=l+1;u<n-3;u++){
						for(int k=u+1;u<n-2;u++){
							for(int op=k+1;op<n-1;op++){
								for(int oi=op+1;oi<n;oi++){
									for(int ui=oi+1;ui<=n;ui++){
										maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]&a[op]&a[oi]&a[ui]);								
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
	if(m==9){
		for(int i=1;i<n-7;i++){
			for(int j=i+1;j<n-6;j++){
				for(int l=j+1;l<n-5;l++){
					for(int u=l+1;u<n-4;u++){
						for(int k=u+1;u<n-3;u++){
							for(int op=k+1;op<n-2;op++){
								for(int oi=op+1;oi<n-1;oi++){
									for(int ui=oi+1;ui<n;ui++){
										for(int yu=ui+1;yu<=n;yu++){
											maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]&a[op]&a[oi]&a[ui]&a[yu]);									
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
	if(m==10){
		for(int i=1;i<n-8;i++){
			for(int j=i+1;j<n-7;j++){
				for(int l=j+1;l<n-6;l++){
					for(int u=l+1;u<n-5;u++){
						for(int k=u+1;u<n-4;u++){
							for(int op=k+1;op<n-3;op++){
								for(int oi=op+1;oi<n-2;oi++){
									for(int ui=oi+1;ui<n-1;ui++){
										for(int yu=ui+1;yu<n;yu++){
											for(int kl=yu+1;kl<=n;kl++){
												maxn=max(maxn,a[i]&a[j]&a[l]&a[u]&a[k]&a[op]&a[oi]&a[ui]&a[yu]&a[kl]);										
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
		cout<<maxn;
		return 0;
	}
	maxn=0;
	for(int i=1;i<=n;i++){
		dfs(i,1,a[i]);
	}
	cout<<maxn;
	return 0;
}
