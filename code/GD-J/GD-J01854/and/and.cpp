#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	int a[n],maxx = -1;
	for(int i = 0;i < n;i++){
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	cout << maxx;
	return 0;
} 
