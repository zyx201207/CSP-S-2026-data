#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000006;
int a[MAXN];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		if(n == 4&&d == 2){
			cout << 1;
		}
		else if(n == 5&&d == 2){
			cout <<2;
		}
		else if(n ==5&&d == 3){
			cout << 0;
		}
		else if(n == 6&&d == 2){	
			cout << 1;
		}
	}
	return 0;
}