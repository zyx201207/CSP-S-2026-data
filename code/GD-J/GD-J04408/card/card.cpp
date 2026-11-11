#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n],c[n],q[10] = {0};
	for(int i = 0;i<n;i++){
		cin>>a[i];
		c[i] = a[i];
	}
	for(int b = 0;b<n-1;b++){
	
	for(int i = 0+b;i<n;i++){
		for(int j = 0+b;j<n;j++){
		if(a[i]==a[j]){
			for(int r = max(i,j);r<n;i++){
				a[r-min(i,j)]=a[r];
				a[r] = 0;
			}
		}
	}
	}
	for(int i = 0+b;i<n;i++){
		if(a[i]!=0)q[a[i]]++;
	}
	for(int i = 0+b;i<n;i++){
		a[i]=c[i];
	}
	}
	
	for(int i = 0;i<n;i++){
		if(q[i]!=0)cout<<q[i]<<' ';
	}
	
	return 0;
}
