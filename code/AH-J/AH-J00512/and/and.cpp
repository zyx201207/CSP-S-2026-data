#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,t,f,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>n>>m;
	cin>>a[1];
	f=a[1];
	t=f;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		f&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==n){
		cout<<f;
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	maxx=0;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxx=max(maxx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						maxx=max(maxx,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int d=l+1;d<=n;d++){
							maxx=max(maxx,a[i]&a[j]&a[k]&a[d]&a[l]);
						}
					}	
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int d=l+1;d<=n;d++){
							for(int r=d+1;r<=n;r++){
								maxx=max(maxx,a[r]&a[i]&a[j]&a[k]&a[d]&a[l]);
							}
						}
					}	
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int d=l+1;d<=n;d++){
							for(int r=d+1;r<=n;r++){
								for(int o=r+1;o<=n;o++){
									maxx=max(maxx,a[o]&a[r]&a[i]&a[j]&a[k]&a[d]&a[l]);
								}
							}
						}
					}	
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
