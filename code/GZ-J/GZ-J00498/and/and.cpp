//GZ-J00498 贵阳市第十八中学 李翼辰 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ma;
long long a[200000+50];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,(a[i]&a[j]));
			}
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ma=max(ma,(a[i]&a[j]&a[k]));
				}
			}
		}
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						ma=max(ma,(a[i]&a[j]&a[k]&a[z]));
					}	
				}
			}
		}		
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]));
						}	
					}	
				}
			}
		}
	}else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							for(int A=x+1;A<=n;A++){
								ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]&a[A]));
							}
						}	
					}	
				}
			}
		}
	}else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							for(int A=x+1;A<=n;A++){
								for(int B=A+1;B<=n;B++){
									ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]&a[A]&a[B]));
								}
							}
						}	
					}	
				}
			}
		}
	}else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							for(int A=x+1;A<=n;A++){
								for(int B=A+1;B<=n;B++){
									for(int C=B+1;C<=n;C++){
										ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]&a[A]&a[B]&a[C]));
									}
								}
							}
						}	
					}	
				}
			}
		}		
	}else if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							for(int A=x+1;A<=n;A++){
								for(int B=A+1;B<=n;B++){
									for(int C=B+1;C<=n;C++){
										for(int D=C+1;D<=n;D++){
											ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]&a[A]&a[B]&a[C]&a[D]));
										}
									}
								}
							}
						}	
					}	
				}
			}
		}
	}else if(m==10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int z=k+1;z<=n;z++){
						for(int x=z+1;x<=n;x++){
							for(int A=x+1;A<=n;A++){
								for(int B=A+1;B<=n;B++){
									for(int C=B+1;C<=n;C++){
										for(int D=C+1;D<=n;D++){
											for(int E=D+1;E<=n;E++){
												ma=max(ma,(a[i]&a[j]&a[k]&a[z]&a[x]&a[A]&a[B]&a[C]&a[D]&a[E]));
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
	}else{
		cout<<0;
		return 0;
	}
	cout<<ma;
	return 0;
}
