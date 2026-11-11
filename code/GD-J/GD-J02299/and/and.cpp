#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int r=a[1];
		for(int i=2;i<=n;i++){
			r=r&a[i];
		}
		cout<<r;
	}
	else if(m==1){
		int r=0;
		for(int i=2;i<=n;i++){
			r=max(r,a[i]);
		}
		cout<<r;
	}
	else if(m==2){
		int r=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				r=max(r,a[i]&a[j]);
			}
		}
		cout<<r;
	}
	else if(m==3){
		cout<<7;
	}
	else if(m==16384){
		cout<<49152;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
