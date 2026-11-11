#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+5],b[n+5][n+5];
	for(int i=0;i<n+5;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		for(int l=0;l<n;l++){
			b[i][l]=0;
		}
	}
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int l=i;l<n;l++){
			b[i][l-m]=a[i];
		}
	}
	for(int i=0;i<n;i++){
		for(int l=i;l<n;l++){
			b[i][l-m]&=a[i+l];
		}	
	}  
	int ans=b[0][0];
	for(int i=0;i<n;i++){
		for(int l=i;l<n;l++){
			if(b[i][l]>ans) ans=b[i][l];
		}
	} 
	cout<<ans;
	return 0;
} 
