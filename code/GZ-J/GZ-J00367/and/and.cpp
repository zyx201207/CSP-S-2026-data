//∏ …≠É| GZ-J00367 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10
int n,  m, maxn = INT_MIN;
int a[N];

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i]; 
		if(a[i] > maxn) maxn = a[i];
	} 
	if(m == 1){
		cout << maxn;
		return 0; 
	}
	cout << a[n-m]; 
	return 0;
}
