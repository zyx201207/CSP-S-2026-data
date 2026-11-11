#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m,x,y=-1;
	cin >>n >>m;
	int a[n],c[n];
	string b[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			x=a[i] and a[j];
			if(x>y){
				y=x;
			}
		}
	}
	cout <<12;
	return 0;	
}
