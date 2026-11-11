#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i-1];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i-1;j++){
			if(a[j-1]>a[j]) {
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	} 
	int l=0,r=n-1,mi=l+(r-l)/2;
	while(l!=r+1){
		mi=l+(r-l)/2;
		int t=0;
		for(int i=1;i<=mi;i++){
			t=t+a[mi]-a[i-1];
		}
		if(t>m) r=mi;
		else if(t<m) l=mi;
		else{
			while(a[mi]==a[mi+1]){
				mi++;
			}
			cout<<mi+1;	
			return 0;
		}
	}
	cout<<l+1;
	return 0;
}
