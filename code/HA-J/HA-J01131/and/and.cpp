#include <bits/stdc++.h>
using namespace std;
const long long int maxn =1e18+5;
long long int a[maxn];
int main() {
	long long int n,m,k=0,l=0;
	cin>>n>>m;
	for(long long int i=0; i<n; i++) {
		cin>>a[i];
		
	}
	for(long long int i=0; i<n; i++) {
		for(long long int  j=i; j<n; j++) {
			if(a[i]&a[j]>=k) {
				k=a[i]&a[j];	
			}l++;
		if(l==m) {
			break;
		}
		
		}
	}
	cout<<k;
	    return 0;
}/*Trick||Treat!
in:262142
2 a
HA-J01131
41081120140715001X
out:2
0
2
2 a
3 a*/
