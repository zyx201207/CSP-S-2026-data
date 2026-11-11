#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a+0,a+n);
	long long s = a[n-1];
	for(int i=n-2;i>=n-m;i--){
		s = s&a[i];
	}
	cout << s;
	return 0;
} 
