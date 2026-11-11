#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d,cnt = 0;
		cin >> n >> d;
		bool is = true;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		for(int i = 3;i <= n;i++){
			if(a[i] - a[i - 1] != a[2] - a[1]) is = false;
		}
		if(is == true){
			int d = a[2] - a[1];
			for(int i = 1;i < n;i++){
				for(int j = i + 1;j <= n;j++){
					if(a[j] - a[i] >= 3 * d && (a[j] - a[i]) < (4 * d)){
						cnt++;
					}	 
				}
			}
			cout << cnt << endl;
			continue;
		}
	}
	return 0;
}
