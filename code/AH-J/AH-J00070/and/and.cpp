#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ct continue
const ll N=2e5+5,inf=1e18;
ll n,m,a[N],mx=-inf,ans=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans=ans&a[i];
		mx=max(mx,a[i]);
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	
	else if(m==1){
		cout<<mx;
		return 0;
	}
	else if(m==2){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j)mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==3){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j&&i!=k&&j!=k)mx=max(mx,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==4){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(i!=j&&i!=k&&j!=k&&i!=l&&j!=l&&k!=l)mx=max(mx,a[i]&a[j]&a[k]&a[l]);
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==5){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int o=1;o<=n;o++){
							if(i!=j&&i!=k&&j!=k&&i!=l&&j!=l&&k!=l&&i!=o&&j!=o&&k!=o&&l!=o)mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]);
						}
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==6){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int o=1;o<=n;o++){
							for(int p=1;p<=n;p++){
								if(i!=j&&i!=k&&j!=k&&i!=l&&j!=l&&k!=l&&i!=o&&j!=o&&k!=o&&l!=o&&p!=i&&p!=j&&p!=k&&p!=l&&p!=o)mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]);
							}
						}
					}
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==7){
		mx=-inf;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int o=1;o<=n;o++){
							for(int p=1;p<=n;p++){
								for(int q=1;q<=n;q++){
									if(i!=j&&i!=k&&j!=k&&i!=l&&j!=l&&k!=l&&i!=o&&j!=o&&k!=o&&l!=o&&p!=i&&p!=j&&p!=k&&p!=l&&p!=o&&q!=i&&q!=j&&q!=k&&q!=l&&q!=o&&q!=p)mx=max(mx,a[i]&a[j]&a[k]&a[l]&a[o]&a[p]&a[q]);
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
