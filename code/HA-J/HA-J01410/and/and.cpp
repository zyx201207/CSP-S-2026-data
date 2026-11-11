#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[1000000],mx=-1e9;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		mx=a[1];
		for(int i=2;i<=n;i++){
			mx=int(mx & a[i]);
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>mx) mx=a[i];
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(int(a[i] & a[j]) > mx) mx=int(a[i] & a[j]);
			}
		}
	}else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++) if(int(a[i] & a[j] & a[k]) > mx) mx=int(a[i] & a[j] & a[k]);
			}
		}
	}else{
		cout<<0;
	}
	cout<<mx;
	return 0;
}

