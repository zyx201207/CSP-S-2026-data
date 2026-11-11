#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	int s[100]={0};
	s[-1]=1000;
	for(int i=1;i<=100;i++){
		if(s[-i]%2==1){
			s[-i-1]=s[-i]/2;
			s[-i]=1;
		}
		else{
			s[-i-1]=s[-i]/2;
			s[-i]=0;
		}
	}
	for(int i=1;i<=100;i++){
		cout<<s[-i]<<" ";
	}
	
	
	
	
	/*
	int m,n;
	int a[100000];
	int b[100000][100000]
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
		b[i]=tmp(a[i]);
	}
	for(int i=0;i<100000;i++){
		for(int j=0;j<100000;j++){
			
		}
	}
	*/
}
