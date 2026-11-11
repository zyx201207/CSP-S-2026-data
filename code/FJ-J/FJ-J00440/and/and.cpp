#include <bits/stdc++.h>
using namespace std;
const int N=100000000;  
long long a[N]; 
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[n-m];
	return 0;	
}
