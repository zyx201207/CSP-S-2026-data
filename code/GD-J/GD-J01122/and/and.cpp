#include <bits/stdc++.h>
using namespace std;
int n,m,a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << a[1];
	}
	return 0;
}
