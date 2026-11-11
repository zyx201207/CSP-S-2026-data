#include <bits/stdc++.h>
using namespace std;

int n;
long long a[INT_MAX];
string S;
string x1;
string x2;
string c;

long long z,h,e;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z = z+a[i];
	}
	h = z;
	z = (z+1)/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			S = S + c[i];
		}
	}

	for(int i=0;i<z;i++){
		x1 = x1+S[i];
	}
	
	if(h%2 == 1){
		for(int i=h-1;i>=z-1;i--){
			x2 = x2+S[i];
		}
	}else{
		for(int i=h-1;i>=z;i--){
			x2 = x2+S[i];
		}
	}

	
	for(int i=0;i<x1.size();i++){
		if(x1[i] != x2[i]){
			e++;
		}
	} 
	cout<<e;
	


	return 0;
}
