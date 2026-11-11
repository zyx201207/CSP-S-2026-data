#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
unsigned long long n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		unsigned long long ans=0;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==3){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==4){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						mx=max(mx,a[i]&a[j]&a[k]&a[b]);						
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==5){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]);	
						}												
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==6){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]&a[d]);
							}									
						}												
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==7){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								for(int e=d+1;e<=n;e++){
									mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]);
								}									
							}									
						}												
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==8){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								for(int e=d+1;e<=n;e++){
									for(int f=e+1;f<=n;f++){
										mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]);
									}									
								}									
							}									
						}												
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==9){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								for(int e=d+1;e<=n;e++){
									for(int f=e+1;f<=n;f++){
										for(int g=f+1;g<=n;g++){
											mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]);
										}										
									}									
								}									
							}									
						}												
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==10){
		unsigned long long mx=-1e20;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int b=k+1;b<=n;b++){
						for(int c=b+1;c<=n;c++){
							for(int d=c+1;d<=n;d++){
								for(int e=d+1;e<=n;e++){
									for(int f=e+1;f<=n;f++){
										for(int g=f+1;g<=n;g++){
											for(int h=f+1;h<=n;h++){
												mx=max(mx,a[i]&a[j]&a[k]&a[b]&a[c]&a[d]&a[e]&a[f]&a[g]&a[h]);
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
		cout<<mx;
		return 0;
	}
	return 0;
}
