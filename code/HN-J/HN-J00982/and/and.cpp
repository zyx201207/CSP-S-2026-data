#include<bits/stdc++.h>
using namespace std;
int n, m, mx=-2000;
void search(int a[], int deep, int c[], int index){
	if(deep > m){
		int t = c[1];
		for(int i=1; i<index; i++)
			t = t & c[i];
		if(mx < t)
			mx = t;
		return;
	}
	for(int i=1; i<=n; i++){
		if(a[i] != -1){
			int t = a[i];
			c[index] = t;
			a[i] = -1;
			search(a, deep+1, c, index+1);
			a[i] = t;
			c[index] = -1;
		}
	}
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int a[220000], c[220000];
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i]; 
		c[i] = -1;
	}
	search(a, 1, c, 1);
	cout << mx;
	return 0;
}
