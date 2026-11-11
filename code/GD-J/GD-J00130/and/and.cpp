#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long ans[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i]=a[i]&a[j];
			}
		}
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
				ans[i]=a[i]&a[j]&a[k];
				}
			}
		}
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int lzc=1;lzc<=n;lzc++){
						ans[i]=a[i]&a[j]&a[k]&a[lzc];
					}
				}
			}
		}
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int lzc=1;lzc<=n;lzc++){
						for(int gjl=1;gjl<=n;gjl++){
							ans[i]=a[i]&a[j]&a[k]&a[lzc]&a[gjl];
						}	
					}
				}
			}
		}
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int lzc=1;lzc<=n;lzc++){
						for(int gjl=1;gjl<=n;gjl++){
							for(int jsq=1;jsq<=n;jsq++){
								ans[i]=a[i]&a[j]&a[k]&a[lzc]&a[gjl]&a[jsq];
							}	
						}	
					}
				}
			}
		}
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int lzc=1;lzc<=n;lzc++){
						for(int gjl=1;gjl<=n;gjl++){
							for(int jsq=1;jsq<=n;jsq++){
								for(int xy=1;xy<=n;xy++){
								ans[i]=a[i]&a[j]&a[k]&a[lzc]&a[gjl]&a[jsq]&a[xy];
							}
							}	
						}	
					}
				}
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans[i]=a[i]&a[j];
			}
		}
	}
	sort(ans+1,ans+1+n);
	cout<<ans[n];
	return 0;
}
