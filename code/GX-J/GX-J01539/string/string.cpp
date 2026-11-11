#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int o=0;
	char m[128128];
	int g[128128];
	int n;
    cin>>n;
	for(int l=0;l<n;l++){
		cin>>g[l];
		cin>>m[l];
	}
	int mo=0;
	for(int a=0;a<n;a++){
		mo=g[a]+mo;
	}
	int duan1=2;
	int duan=g[0];
	char ds=m[0];
	char moes=m[n];
	int shu=0;
	int l=mo;
	for(int b=0;b<mo;b++){
		if(b>duan){
			shu++;
			ds=m[shu];
			duan=g[shu]+duan;
		}
		if(moes<mo-g[l-1]){
		moes=m[l-duan1];
		duan1++;
	}
		if(ds!=moes){
           o++;
			
		}
		mo--;
	}
	cout<<o-1;
			 return 0;
		 }



