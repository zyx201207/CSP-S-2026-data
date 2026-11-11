#include <bits/stdc++.h>
using namespace std;

int b[105];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.our","w",stdout);
	int n,m,z=0,q[n];
	cin>> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	q[0] =-1; 
	for(int w=0; w<m;w++){
		for(int i=0;i < n;i++) {
			if(a[i] >z) {
				for(int e=0;e < n;e++){
					if(q[e] == i&&i !=1){
						a[i] = z;
					}
				}
				z = a[i];
				if(i = n-1){
					q[w]=i;
				}
			}
		}
		for(int i=0;i < m;i++){
			z = z and b[i];
			
		}
	}
	cout << z;
	return 0;
}
