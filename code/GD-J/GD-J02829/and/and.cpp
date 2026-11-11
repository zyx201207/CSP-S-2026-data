#include<bits/stdc++.h>
using namespace std;
int a[100001];
int maxn = -20000000;
int main(){
	freopen("and.in","r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		int x = a[i];
		for(int j = 1; j<= m;j++){
			for(int k = i+1;k<=n;k++){
				x &= a[k];
				if(x> maxn) maxn = x;
			}
		}
	}
	cout << maxn;
	return 0;
}
