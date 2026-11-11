#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n>>m;
	int a[200001];
	int p = 0;
	for (int i = 0;i<n;i++){
		cin >> a[i];
		p = max(a[i],p);
	}

	if(m == 1){
		cout << p;	
	}

	return 0;
}
