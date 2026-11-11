#include<iostream>
using namespace std;
int main(){
	int n, m, ans = 0;
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int x[n];
	for(int i=0;i<n;i++){
		cin >> x[i];
	}
	for(int i=0;i<=n;i++){
		int a = x[i];
		for(int j=1;j<m;j++){
			a = a&x[j];
		}
		if(a>ans){
			ans = a;
		}
	}
	cout << ans;
} 
