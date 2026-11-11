#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,mmax=0,s=0;
long long a[2000001];
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
if(m==2){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			s=a[i]&a[j];
			mmax=max(mmax,s);
		}
	}
	cout<<mmax;
	return 0;
}else if(m==3){
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int d=j+1;d<n;d++){
			s=a[i]&a[j]&a[d];
			mmax=max(mmax,s);
			}
		}
	}
	cout<<mmax;
	return 0;
}else if(m==4){
	for(int i=0;i<n-3;i++){
		for(int j=i+1;j<n-2;j++){
			for(int d=j+1;d<n-1;d++){
				for(int x=d+1;x<n;x++){
				s=a[i]&a[j]&a[d]&a[x];
				mmax=max(mmax,s);
				}
			}
		}
	}
	cout<<mmax;
}else if(m==5){
	for(int i=0;i<n-4;i++){
		for(int j=i+1;j<n-3;j++){
			for(int d=j+1;d<n-2;d++){
				for(int x=d+1;x<n-1;x++){
					for(int y=x+1;y<n;y++){
					s=a[i]&a[j]&a[d]&a[x]&a[y];
					mmax=max(mmax,s);
					}
				}
			}
		}
	}
	cout<<mmax;
}else if(m==6){
	for(int i=0;i<n-5;i++){
		for(int j=i+1;j<n-4;j++){
			for(int d=j+1;d<n-3;d++){
				for(int x=d+1;x<n-2;x++){
					for(int y=x+1;y<n-1;y++){
						for(int u=y+1;u<n;u++){
						s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u];
						mmax=max(mmax,s);
						}
					}
				}
			}
		}
	}
	cout<<mmax;
}else if(m==7){
	for(int i=0;i<n-6;i++){
		for(int j=i+1;j<n-5;j++){
			for(int d=j+1;d<n-4;d++){
				for(int x=d+1;x<n-3;x++){
					for(int y=x+1;y<n-2;y++){
						for(int u=y+1;u<n-1;u++){
							for(int r=u+1;r<n;r++){
							s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r];
							mmax=max(mmax,s);
							}
						}
					}
				}
			}
		}
	}
	cout<<mmax;
}else if(m==8){
	for(int i=0;i<n-7;i++){
		for(int j=i+1;j<n-6;j++){
			for(int d=j+1;d<n-5;d++){
				for(int x=d+1;x<n-4;x++){
					for(int y=x+1;y<n-3;y++){
						for(int u=y+1;u<n-2;u++){
							for(int r=u+1;r<n-1;r++){
								for(int l=r+1;l<n;l++){
								s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r]&a[l];
								mmax=max(mmax,s);
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<mmax;
}else if(m==9){
	for(int i=0;i<n-8;i++){
		for(int j=i+1;j<n-7;j++){
			for(int d=j+1;d<n-6;d++){
				for(int x=d+1;x<n-5;x++){
					for(int y=x+1;y<n-4;y++){
						for(int u=y+1;u<n-3;u++){
							for(int r=u+1;r<n-2;r++){
								for(int l=r+1;l<n-1;l++){
									for(int z=l+1;z<n;z++){
									s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r]&a[l]&a[z];
									mmax=max(mmax,s);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<mmax;
}else if(m==10){
	for(int i=0;i<n-9;i++){
		for(int j=i+1;j<n-8;j++){
			for(int d=j+1;d<n-7;d++){
				for(int x=d+1;x<n-6;x++){
					for(int y=x+1;y<n-5;y++){
						for(int u=y+1;u<n-4;u++){
							for(int r=u+1;r<n-3;r++){
								for(int l=r+1;l<n-2;l++){
									for(int z=l+1;z<n-1;z++){
										for(int b=z+1;b<n;b++){
									s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r]&a[l]&a[z]&a[b];
									mmax=max(mmax,s);
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
	cout<<mmax;
}else if(m==11){
	for(int i=0;i<n-10;i++){
		for(int j=i+1;j<n-9;j++){
			for(int d=j+1;d<n-8;d++){
				for(int x=d+1;x<n-7;x++){
					for(int y=x+1;y<n-6;y++){
						for(int u=y+1;u<n-5;u++){
							for(int r=u+1;r<n-4;r++){
								for(int l=r+1;l<n-3;l++){
									for(int z=l+1;z<n-2;z++){
										for(int b=z+1;b<n-1;b++){
											for(int v=b+1;v<n;v++){
											s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r]&a[l]&a[z]&a[b]&a[v];
											mmax=max(mmax,s);
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
	cout<<mmax;
}else if(m==12){
	for(int i=0;i<n-11;i++){
		for(int j=i+1;j<n-10;j++){
			for(int d=j+1;d<n-9;d++){
				for(int x=d+1;x<n-8;x++){
					for(int y=x+1;y<n-7;y++){
						for(int u=y+1;u<n-6;u++){
							for(int r=u+1;r<n-5;r++){
								for(int l=r+1;l<n-4;l++){
									for(int z=l+1;z<n-3;z++){
										for(int b=z+1;b<n-2;b++){
											for(int v=b+1;v<n-1;v++){
												for(int g=v+1;g<n;g++){
												s=a[i]&a[j]&a[d]&a[x]&a[y]&a[u]&a[r]&a[l]&a[z]&a[b]&a[v];
												mmax=max(mmax,s);
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
	cout<<mmax;
}else if(m==1){
	for(int i=0;i<n;i++){
	mmax=(mmax,a[i]);
	cout<<mmax;
}
}else{
	cout<<1;
}
return 0;
}
