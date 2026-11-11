#include <bits/stdc++.h>
using namespace std;
const int nnn = (1<<31)-1; 
int d[200005] = {nnn};
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		for(int j = m ; j > 0;j--){
			d[j] = max(d[j-1] & a, d[j]);
		}
	}
	cout<<d[m];
	return 0;
}
