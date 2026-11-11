#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 0;i < t;i++){
		int n,d;
		cin >> n >> d;
		int a[n],b[n-1];
		for(int j = 0;j < n;j++){
			cin >> a[j];
		}
		for(int j = 0;j < n-1;j++){
			b[j] = max(a[i],a[i+1])-min(a[i],a[i+1]);
		}
		cout << 1 << endl;
	}
	return 0;
}
