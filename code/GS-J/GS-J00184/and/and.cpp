#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(a[j+1]>a[j]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	}
	int r=a[1];
	for(int i=2;i<=m;i++){
		r=r&a[i];
	}
	cout<<r;
	
	return 0;
}
