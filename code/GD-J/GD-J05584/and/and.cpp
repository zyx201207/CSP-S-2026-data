#include <bits/stdc++.h> 
using namespace std;

int n,m,a[200000];
void abc(int l,int v,int t) {
	if (l == m) {
		cout << v << endl;
		return;
	}
	for (int i = t+1;i < n;i++) {
		abc(l+1,v&a[i],t);
	}
}

int main() {
	 
	 freopen("and.in","r",stdin);
	 freopen("and.out","r",stdout);
	cin >> n >> m;
	for (int i =0;i < n;i++) {
		cin >> a[i];
	}
	for (int i = 0;i < n-1;i++) {
		abc(1,a[i],i);
	}
	
	

	return 0;
}

