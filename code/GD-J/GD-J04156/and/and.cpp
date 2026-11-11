#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
const ll inf=0x3f3f3f3f;
ll n,m,a[maxn],maxx=-inf,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	cnt=a[1];
	for(ll i=2;i<=n;i++)cnt&=a[i];
	if(m==1)cout<<maxx;
	else if(m==n)cout<<cnt;
	else if(m==2){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++)maxx=max(maxx,a[i]&a[j]);
		}
		cout<<maxx;
	}else if(m==3){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++)maxx=max(maxx,a[i]&a[j]&a[l]);
			}
		}
		cout<<maxx;
	}else if(m==4){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]);
				}
			}
		}
		cout<<maxx;
	}else if(m==5){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++){
						for(ll p=o+1;p<=n;p++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]&a[p]);
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==6){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++){
						for(ll p=o+1;p<=n;p++){
							for(ll q=p+1;q<=n;q++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]&a[p]&a[q]);
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==7){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++){
						for(ll p=o+1;p<=n;p++){
							for(ll q=p+1;q<=n;q++){
								for(ll ii=q+1;ii<=n;ii++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]&a[p]&a[q]&a[ii]);
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==8){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++){
						for(ll p=o+1;p<=n;p++){
							for(ll q=p+1;q<=n;q++){
								for(ll ii=q+1;ii<=n;ii++){
									for(ll jj=ii+1;jj<=n;jj++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]&a[p]&a[q]&a[ii]&a[jj]);
								}
							}
						}
					}
				}
			}
		}
		cout<<maxx;
	}else if(m==9){
		maxx=-inf;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll l=j+1;l<=n;l++){
					for(ll o=l+1;o<=n;o++){
						for(ll p=o+1;p<=n;p++){
							for(ll q=p+1;q<=n;q++){
								for(ll ii=q+1;ii<=n;ii++){
									for(ll jj=ii+1;jj<=n;jj++){
										for(ll k=jj+1;k<=n;k++)maxx=max(maxx,a[i]&a[j]&a[l]&a[o]&a[p]&a[q]&a[ii]&a[jj]&a[k]);
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
