#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],s[200005];
bool b[200005];
long long ans = 0;
long long maxx=-1e9,maxxx=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(i==1){
			ans = a[i];
		}else{
			ans &= a[i];
		}
	}
	if(m==1){
		cout<<maxx;
	}else if(m==n){
		cout<<ans;
	}else if(m==2){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(i!=j){
					maxxx=max(maxxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxxx;
	}else if(m==3){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					if(i!=j!=k){
						maxxx=max(maxxx,a[i]&a[j]&a[k]);
					}	
				}
			}
		}
		cout<<maxxx;
	}
	else if(m==4){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				for(int k = 1;k<=n;k++){
					for(int l = 1;l<=n;l++){
						if(i!=j!=k!=l){
							maxxx=max(maxxx,a[i]&a[j]&a[k]&a[l]);
						}	
					}
				}
			}
		}
		cout<<maxxx;
	}
	return 0;
}

