#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[200009],b[200009],c[10000009];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int c=1;
		while(a[i]){
			b[i]+=a[i]%2*c;
			c*=10;
			a[i]=a[i]/2;
		}
	}
	for(int i=1;i<=n;i++){
		
	}
}
