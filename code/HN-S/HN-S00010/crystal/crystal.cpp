#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],mx=10e-12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	sort(a,a+n-1);
	cout<<a[2]+5; 
	return 0;
}
