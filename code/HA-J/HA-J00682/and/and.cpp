#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx=-1e9,sum=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	if(m==1){
		for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
		cout<<maxx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,(a[i]&a[j]));
		}
		cout<<maxx;
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				if(sum==-1)sum=a[j];
				else sum=(sum&a[j]);
			}
			maxx=max(maxx,sum);
			sum=-1;
		}
		cout<<maxx;
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(maxx,(a[i]&a[j]&a[k]));
				}
			}
		}
		cout<<maxx;
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++)
						maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]));
				}
			}
		}
		cout<<maxx;
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int oo=o+1;oo<=n;oo++)
							maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]&a[oo]));
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int oo=o+1;oo<=n;oo++){
							for(int ooo=oo+1;ooo<=n;ooo++)
							maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]&a[oo]&a[ooo]));
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int oo=o+1;oo<=n;oo++){
							for(int ooo=oo+1;ooo<=n;ooo++){
								for(int o7=ooo+1;o7<=n;o7++)
								maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]&a[oo]&a[ooo]&a[o7]));
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int oo=o+1;oo<=n;oo++){
							for(int ooo=oo+1;ooo<=n;ooo++){
								for(int o7=ooo+1;o7<=n;o7++){
									for(int o8=o7+1;o8<=n;o8++)
									maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]&a[oo]&a[ooo]&a[o7]&a[o8]));
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==9){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int o=k+1;o<=n;o++){
						for(int oo=o+1;oo<=n;oo++){
							for(int ooo=oo+1;ooo<=n;ooo++){
								for(int o7=ooo+1;o7<=n;o7++){
									for(int o8=o7+1;o8<=n;o8++){
										for(int o9=o8+1;o9<=n;o9++)
										maxx=max(maxx,(a[i]&a[j]&a[k]&a[o]&a[oo]&a[ooo]&a[o7]&a[o8]&a[o9]));
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
