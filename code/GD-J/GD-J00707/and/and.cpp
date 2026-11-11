#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],zz,zd=-114514;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			zd=max(zd,a[i]);
		}
	}
	else if(m==2){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			zz=a[i]&a[j];
			zd=max(zd,zz);
		}
	}
}
	else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					zz=a[i]&a[j]&a[k];
					zd=max(zd,zz);
				}
			}
		}
	}
	else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int c=k+1;c<n;c++){
						zz=a[i]&a[j]&a[k]&a[c];
						zd=max(zd,zz);
					}
				}
			}
		}
	}
	else if(m==5){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int c=k+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							zz=a[i]&a[j]&a[k]&a[c]&a[d];
							zd=max(zd,zz);
						}
					}
				}
			}
		}
	}
	else if(m==6){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int c=k+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								zz=a[i]&a[j]&a[k]&a[c]&a[d]&a[e];
								zd=max(zd,zz);
							}
						}
					}
				}
			}
		}
	}
	else if(m==7){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int c=k+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								for(int f=e+1;f<n;f++){
									zz=a[i]&a[j]&a[k]&a[c]&a[d]&a[e]&a[f];
									zd=max(zd,zz);
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==8){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int c=k+1;c<n;c++){
						for(int d=c+1;d<n;d++){
							for(int e=d+1;e<n;e++){
								for(int f=e+1;f<n;f++){
									for(int g=f+1;g<n;g++){
										zz=a[i]&a[j]&a[k]&a[c]&a[d]&a[e]&a[f]&a[g];
										zd=max(zd,zz);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if(m==n){
		zd=a[0];
		for(int i=1;i<n;i++){
			zd=zd&a[i];
		}
	}
	cout<<zd;
}
