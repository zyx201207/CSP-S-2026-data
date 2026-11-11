#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int x=0,y=0,z=0;
	int a[500005]={};
	int b[500005]={};
	int c[500005]={};
	cin>>n;
	cin>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	b[0]=a[0];
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]==a[j]){
				x++;
			}
			if(x==0){
				b[i]=a[i];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]==b[j]){
				c[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		int max=0;
		if(c[i]>=max){
			max=c[i];
			y=b[i];
		}
	}
	for(int i=0;i<n;i++){
		if(m!=0&&a[i]<y){
			while(a[i]==y){
				a[i]++;
				m--;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==y){
			z++;
		} 
	}
	cout<<z;
	return 0;	
} 
