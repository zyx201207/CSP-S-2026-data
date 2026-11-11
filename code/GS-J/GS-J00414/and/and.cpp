#include<bits/stdc++.h>
int a[200100];
using namespace std;
int main(){
	preopen("and.in",'r',stdin);
	preopen("and.out",'w',stdout);
	int n,m,r;
	int b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int e=0;e<n;e++){
			r=a[i];
			for(int j=1;j<m;j++){
				r=r&a[i+j+e];
			}
			if(r>b){
				b=r;
			}
		}
	}
	cout<<b;
}
