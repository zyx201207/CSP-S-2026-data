#include<bits/stdc++.h>
using namespace std;
int n , m;
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int sz[200010];
	for(int i = 1 ; i <= n; i++){
		cin >> sz[i];
	}
	sort(sz + 1 , sz + n + 1 , cmp);
	cout << sz[m];
	return 0;
}
