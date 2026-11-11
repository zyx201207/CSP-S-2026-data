#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n,m,a[254514],sum=0,maxa=LONG_LONG_MIN;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=0;i<n-1;i++){
			sum=(a[i]&a[i+1]);
			maxa=max(maxa, sum);
		}
	}else if(m==1){
		for(int i=1;i<=n;i++){
			maxa=max(maxa, a[i]);
		}
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(a[i]&sum);
		}
	}else{
		for(int i=0;i<n-1;i++){
			sum=a[i];
			for(int j=i+1;j<=i+m;j++){
				sum=(sum&a[i+1]);
				maxa=max(maxa, sum);
			}
			
		}
	}
	cout<<maxa;
	return 0;
}
