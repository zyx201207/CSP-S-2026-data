#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000];
string a1[1000000]; 
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	long long zs;
    zs = a[n-1];
	for(int i=2;i<=m;i++){
		zs = zs and a[n-i];
	}
	cout << zs;
	return 0;
}
