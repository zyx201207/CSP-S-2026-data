#include <iostream>
#include <algorithm>
using namespace std;
long n, mat[1000086];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i = 0; i < n; i++) cin>>mat[i];
	sort(mat, mat + n);
	cout<<mat[n / 2]<<"\n";
	return 0;
}
