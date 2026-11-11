#include<bits/stdc++.h>
using namespace std;
int n,m,ans,A[1000006];
bool cmp(int a,int b){
	return a > b;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	sort(A,A+n,cmp);//½µÐò
	ans = A[0];
	for(int i = 0; i < m; i++) {
		ans = A[i];
	}
	cout << ans;
	return 0;
}
/*

*/

