#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,z=0,mx=0;
	cin >> n >> m;
	long long a[n],ans[n*n*m];
	for (long long i = 0;i<n*n*m;i++){
		ans[i] = 0;
	}
	for (long long i = 0;i<n;i++){
		cin >> a[i];
	}
	for (long long i = 0;i<n;i++){
		for (long long j = i;j<n;j++){
			ans[z] = a[i]&a[j];
		}
	}
	for (long long i = 0;i<n*n*m;i++){
		if (ans[i] > mx){
			mx = ans[i];
		}
	}
	cout << mx;
	return 0;
}
