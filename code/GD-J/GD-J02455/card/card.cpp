#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[500005]={};
	int b[500005]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	for(int i=0;i<n;i++){
		int x=0;
		for(int j=0;j<n-i;j++){
			for(int k=0;k<j+1;k++){
				if(a[j]==a[k]){
					x=0;	
					}
				x*=10;
				x+=a[j+i];
				}
		b[i]=x;
			}
		}
	for(int i=0;i<n;i++){
		int y=0;
		int c[500005]={};
		for(int j=0;j<n;j++){
			c[j]=b[i]%j;
			if(a[i]==c[j]){
				y+=1;
				}
			}
			cout<<y;
		}
	}
	return 0;
}

