#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string a,c;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		cin >> c[i]	;
	}
	for(int i=0;i<n;i++){
		if(c[i]!=c[n-i]){
			t+=min(a[i],a[n-i]);
		}
	}
	cout << t;
	return 0;
} 
