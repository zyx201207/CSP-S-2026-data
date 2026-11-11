#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=1,x,z=0;
	int a[10001];
	string b,c,d;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=1;i<=n;i++){
		x=s+a[i];
		for(int j=s;j<x;j++){
			c[j]=b[i];
		}
		s=s+a[i];
	}
	for(int i=1;i<=x;i++){
		for(int j=i+1;j>=i;j--){
			if(c[i]!=c[j]){
				z++;
				break;
			}
		}
	}
	cout << z-1;
	return 0;
}
