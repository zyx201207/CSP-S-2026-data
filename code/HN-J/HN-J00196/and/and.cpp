#include <bits/stdc++.h> 
using namespace std;
int n,m,maxn;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(m==1){
		for(int i = 1; i <= n; i++){
			maxn = max(maxn,a[i]);
		}
	}
	if(m==n){
		maxn = a[1]&&a[2];
		for(int i = 3; i <= n; i++){
			maxn = maxn&&a[i];
		}
	}
	cout << maxn;
	return 0;
}
