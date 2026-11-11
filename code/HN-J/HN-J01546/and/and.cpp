#include<bits/stdc++.h>
using namespace std;
int main( ){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int d1=-32766;
	int d2=-32766;
	int d3=-32766;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d1=max(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==d1){
			a[i]=-32766;
			continue;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d2=max(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==d2){
			a[i]=-32766;
			continue;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			d3=max(a[i],a[j]);
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==d3){
			a[i]=-32766;
			continue;
		}
	}
	cout<<d1&&d2&&d3;
	return 0;
} 
