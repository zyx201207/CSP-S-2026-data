#include<iostream>
using namespace std;

int main(){
	int n,m,z;
	cin>>n>>m;
	int a[n],max[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		max[i]=0;
		for(int j=0;j<n;j++){
			if(a[j]>max[i]){
				max[i]=a[j];
				a[j]=0;
			}
		}
	}
	z=max[0];
	for(int i=1;i<m;i++){
		z=z&max[i];
	}
	cout<<z;
	
	return 0;
} 
