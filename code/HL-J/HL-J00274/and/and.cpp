#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int maxx = -1;
	int andd = 0;
	for(int i = 1;i<=n;i++){
		for(int j = 1 ; j <= m ; j++){
			int andd = a[i] and a[j];
			cout<< a[i] << " " << a[j] << " " << andd << endl;
			if(andd>maxx) maxx=andd;
		}
	}
	cout << maxx;
	return 0;
}
