#include<bits/stdc++.h>
using namespace std;
int c, t;
long long a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		cin >> a[i];
		int edg = 6;
		for(int i = 1; i <= n-2; i++)
		if(a[i+2]-a[i+1]!=a[i+1]-a[i])
		edg = 3;
		if(edg == 6){
			int cha = a[2]-a[1];
			if(d<=cha){
				cout << 0 << "\n";
				continue;
			}else if(d>=a[n]-a[1]){
				cout << 0 << "\n";
				continue;
			}else{
				cout << a[n]-a[1]-d-d+2 << "\n";
				continue;
			}
		}
		cout << 0 << "\n";
	}
	return 0;
}
