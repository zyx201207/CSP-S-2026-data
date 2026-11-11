#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[5000];

int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {

		k=a[i];
		if(a[i]==k) {
			a[i]=0;
			for(int j=i; j<n; j++) {
				a[j]=0;
			}
			if(k==0) {
				continue;
			}

		}else{
			a[i+1]=k;
		}
	}for(int i=0; i<m; i++) {
		if(a[i]==0){
			continue;
		}
		cout<<a[i];
	}
	return 0;
}//Trick||Treat!
