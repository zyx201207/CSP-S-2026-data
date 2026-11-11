#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200086],sum,maxn;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	if(m==3){
		for(int q=1;q<=n;q++){
			for(int i=q+1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxn=max(maxn,a[i]&a[j]&a[q]);
				}
			}
		}
	}
	if(m==4){
		for(int w=1;w<=n;w++){
			for(int q=w+1;q<=n;q++){
				for(int i=q+1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						maxn=max(maxn,a[i]&a[j]&a[q]&a[w]);
					}
				}
			}
		}
	}
	if(m==5){
		for(int e=1;e<=n;e++){
			for(int w=e+1;w<=n;w++){
				for(int q=w+1;q<=n;q++){
					for(int i=q+1;i<=n;i++){
						for(int j=i+1;j<=n;j++){
							maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]);
						}
					}
				}
			}
		}
	}
	if(m==6){
		for(int r=1;r<=n;r++){
			for(int e=r+1;e<=n;e++){
				for(int w=e+1;w<=n;w++){
					for(int q=w+1;q<=n;q++){
						for(int i=q+1;i<=n;i++){
							for(int j=i+1;j<=n;j++){
								maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]);
							}
						}
					}
				}
			}
		}
	}
	if(m==7){
		for(int t=1;t<=n;t++){
			for(int r=t+1;r<=n;r++){
				for(int e=r+1;e<=n;e++){
					for(int w=e+1;w<=n;w++){
						for(int q=w+1;q<=n;q++){
							for(int i=q+1;i<=n;i++){
								for(int j=i+1;j<=n;j++){
									maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]);
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==8){
		for(int y=1;y<=n;y++){
			for(int t=y+1;t<=n;t++){
				for(int r=t+1;r<=n;r++){
					for(int e=r+1;e<=n;e++){
						for(int w=e+1;w<=n;w++){
							for(int q=w+1;q<=n;q++){
								for(int i=q+1;i<=n;i++){
									for(int j=i+1;j<=n;j++){
										maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(m==9){
		for(int u=1;u<=n;u++){
			for(int y=u+1;y<=n;y++){
				for(int t=y+1;t<=n;t++){
					for(int r=t+1;r<=n;r++){
						for(int e=r+1;e<=n;e++){
							for(int w=e+1;w<=n;w++){
								for(int q=w+1;q<=n;q++){
									for(int i=q+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
											maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]);
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
	if(m==10){
		for(int o=1;o<=n;o++){
			for(int u=o+1;u<=n;u++){
				for(int y=u+1;y<=n;y++){
					for(int t=y+1;t<=n;t++){
						for(int r=t+1;r<=n;r++){
							for(int e=r+1;e<=n;e++){
								for(int w=e+1;w<=n;w++){
									for(int q=w+1;q<=n;q++){
										for(int i=q+1;i<=n;i++){
											for(int j=i+1;j<=n;j++){
												maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]);
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
	}
	if(m==11){
		for(int p=1;p<=n;p++){
			for(int o=p+1;o<=n;o++){
				for(int u=o+1;u<=n;u++){
					for(int y=u+1;y<=n;y++){
						for(int t=y+1;t<=n;t++){
							for(int r=t+1;r<=n;r++){
								for(int e=r+1;e<=n;e++){
									for(int w=e+1;w<=n;w++){
										for(int q=w+1;q<=n;q++){
											for(int i=q+1;i<=n;i++){
												for(int j=i+1;j<=n;j++){
													maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[p]);
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
		}
	}
	if(m==12){
		for(int s=1;s<=n;s++){
			for(int p=s+1;p<=n;p++){
				for(int o=p+1;o<=n;o++){
					for(int u=o+1;u<=n;u++){
						for(int y=u+1;y<=n;y++){
							for(int t=y+1;t<=n;t++){
								for(int r=t+1;r<=n;r++){
									for(int e=r+1;e<=n;e++){
										for(int w=e+1;w<=n;w++){
											for(int q=w+1;q<=n;q++){
												for(int i=q+1;i<=n;i++){
													for(int j=i+1;j<=n;j++){
														maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]);
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
			}	
		}
	}
	if(m==13){
		for(int d=1;d<=n;d++){
			for(int s=d+1;s<=n;s++){
				for(int p=s+1;p<=n;p++){
					for(int o=p+1;o<=n;o++){
						for(int u=o+1;u<=n;u++){
							for(int y=u+1;y<=n;y++){
								for(int t=y+1;t<=n;t++){
									for(int r=t+1;r<=n;r++){
										for(int e=r+1;e<=n;e++){
											for(int w=e+1;w<=n;w++){
												for(int q=w+1;q<=n;q++){
													for(int i=q+1;i<=n;i++){
														for(int j=i+1;j<=n;j++){
															maxn=max(maxn,a[i]&a[j]&a[q]&a[w]&a[e]&a[r]&a[t]&a[y]&a[u]&a[o]&a[p]&a[s]&a[d]);
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
				}	
			}
		}
	}
	if(m==14){
		for(int f=1;f<=n;f++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==15){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==16){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==17){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==18){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==19){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	if(m==20){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	cout<<maxn;
    return 0;
}
