#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200010]; 
ll s[200010];
ll ma=-1e18;
ll ma1=-1e18;
ll cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ma1=max(ma1,a[i]);
	}
	if(m==1){
		cout<<ma1<<endl;
		return 0;
	}
	if(m==n){
		cnt=a[1];
		for(ll i=2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt<<endl;
		return 0;
	}
	if(m==3){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					ma=max(ma,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==4){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						ma=max(ma,a[i]&a[j]&a[k]*a[l]);
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==5){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						for(ll m=l+1;m<=n;m++){
							ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[m]);
						}
						
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==6){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						for(ll m=l+1;m<=n;m++){
							for(ll o=m+1;o<=n;o++){
								ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[m]&a[o]);
							}
						}
						
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==7){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						for(ll m=l+1;m<=n;m++){
							for(ll o=m+1;o<=n;o++){
								for(ll p=o+1;p<=n;p++){
									ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p]);
								}
							}
						}
						
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==8){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						for(ll m=l+1;m<=n;m++){
							for(ll o=m+1;o<=n;o++){
								for(ll p=o+1;p<=n;p++){
									for(ll q=p+1;q<=n;q++){
										ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p]&a[q]);
									}
									
								}
							}
						}
						
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
	if(m==9){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					for(ll l=k+1;l<=n;l++){
						for(ll m=l+1;m<=n;m++){
							for(ll o=m+1;o<=n;o++){
								for(ll p=o+1;p<=n;p++){
									for(ll q=p+1;q<=n;q++){
										for(ll r=q+1;r<=n;r++){
											ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[m]&a[o]&a[p]&a[q]&a[r]);
										}
										
									}
									
								}
							}
						}
						
					}
				}
			}
		}
		cout<<ma<<endl;
		return 0;
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=i+1;j<=n;j++){
//			ma=max(ma,a[i]&a[j]);
//		}
//	}
//	cout<<ma<<endl;
    cout<<endl<<endl<<endl<<pow(20,10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 2
3 15 12 12

*/
