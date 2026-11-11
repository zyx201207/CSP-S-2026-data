#include<bits/stdc++.h>
using namespace std; 

int n, m, a[500005]={}, b[500005]={}, c[500005]={}; 

int main() {
	freopen("card.in", "r", stdin); 
	freopen("card.out", "w", stdout); 
	cin>>n>>m; 
	for(int i=1; i<=n; i++) {
		cin>>a[i]; 		
	} 
	for(int abc=1; abc<=n; abc++) {
		int top=1; 
		for(int i=abc; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(b[j]==a[i]) {
					memset(b, 0, sizeof(b)); 
					top=1; 
					b[top]=a[i]; 
				} else {
					b[top]=a[i]; 
					top++; 
					break; 
				}
			}
		}
		for(int i=1; i<=top; i++) {
			c[b[i]]++; 
		}
		memset(b, 0, sizeof(b)); 
	} for(int i=1; i<=m; i++) {
		cout<<c[i]<<' '; 
	} 
	return 0; 
} 
