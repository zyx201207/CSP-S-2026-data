#include <bits/stdc++.h>
using namespace std;
long long n,maxn=0,m; 
int a[101105];
int s[101105];
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout"); 
	// a and b
	cin >> n >> m;
	for(int i=0;i<n;i++){//∂¡»° 
		cin >> a[i];
	}
	
	for(int i=0;i<n;i++){
		if(i=0)      continue;
		if((a[i-1] and a[i])>maxn)	maxn = a[i-1] and a[i];
	}//max≈–∂œΩ· ¯ 
	cout << maxn;
	return 0;
}

