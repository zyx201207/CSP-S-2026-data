#include<bits/stdc++.h>
using namespace std; 

int a[200005], n, vis[200005], minn=INT_MAX; string s="", t, c[200005]; 

int main() {
	freopen("string.in", "r", stdin); 
	freopen("string.out", "w", stdout); 
	cin>>n; 
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i]; 		
	} for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			s+=c[i]; 
		}
	} 
	for(int i=s.size()-1; i>=0; i--) {
		s[i]=s[s.size()-i-1]; 
		t=s; reverse(t.begin(), t.end()); 
		if(s==t) {
			cout<<s.size()-i; 
			return 0; 
		}
	}
	return 0; 
}
