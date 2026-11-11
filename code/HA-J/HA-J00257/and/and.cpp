#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for(int i=0;i<n;i++){
		cin >>a[i];
	}
	
	int maix=0;
	if(m==2){
		for(int i=0;i<n;i++){
			maix = max(maix,a[i]&a[i+1]);
		}	
	}else if(m==3){
		for(int i=0;i<n;i++){
		maix = max(maix,a[i]&a[i+1]&a[i+2]);
		}
	}
	cout << maix;
	
	return 0;
}
