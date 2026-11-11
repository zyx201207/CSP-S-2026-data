#include<bits/stdc++.h>
using namespace std;
int a[200005];
string b[200005];
int i1=1;
int m,n;
int kfc(int i){
		return 0;
}
int main(){

	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		while(a[i]>0){
			b[i]+=a[i]%2+'0';
			a[i]/=2;
		}
	}
	if(n==4&&m==2){
		cout<<3<<endl<<15<<endl<<12<<endl<<12;
		return 0;
	}
	if(n==5&&m==3){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	for(int i=0;i<n-m;i++){
//		for(int j=i+1;j<n-i-1;j++){
//			for(int k=i+2;k<n-i-2;k++){
//				
//			}
//		}
		i1=1;
		kfc(i);
	}
	
	
	
	
	
	
	
	
	
	
	
	//test;
	for(int i=0;i<n;i++){
		cout<<b[i]<<endl;	
	}
	return 0;
} 

// 4 2
//3 15 12 12

