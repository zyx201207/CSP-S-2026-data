#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;
	long long ans=0;
	long long a[100000]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		ans=a[n-1];
	}else if(m==n){
		for(int i=0;i<n;i++){
			a[0]=a[0]&a[i];
		}
		ans=a[0];
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i]&a[j]>ans&&i!=j){
					ans=a[i]&a[j];
				}
			}
		}
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(a[i]&a[j]&a[k]>ans&&i!=j&&j!=k&&k!=i){
						ans=a[i]&a[j]&a[k];
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
