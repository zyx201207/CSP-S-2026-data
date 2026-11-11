#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx,ans=pow(2,20)-1;
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]!=a[j]) mx=max(a[i]&a[j],mx);
			}
		}
		cout<<mx;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i]!=a[j]&&a[j]!=a[k]&&a[i]!=a[k]) mx=max(a[i]&a[j]&a[k],mx);
				}
			}
		}
		cout<<mx;
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(a[i]!=a[j]&&a[i]!=a[k]&&a[i]!=a[l]&&a[j]!=a[k]&&a[j]!=a[l]&&a[k]!=a[l]) mx=max(a[i]&a[j]&a[k]&a[l],mx); mx=max(a[i]&a[j],mx);
					}
				}
			}
		}
		cout<<mx;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else{
		for(int i=m;i>=1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
