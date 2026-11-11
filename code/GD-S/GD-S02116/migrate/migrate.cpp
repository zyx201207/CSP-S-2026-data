#include <iostream>
using namespace std;

long long n,d;
long long x[10000001];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> x[i];
		}
		long long s[10000001]={};
		for (int i = 1;i <= n;i++) s[i] = 0;
		int ct[10000001]={0};
		for (int i = 1;i <= n;i++){
			ct[i] = 0;
		}
		for (int i = 1;i <= n;i++){

			int le;
			int ri;
			for (int j = 1;j <= n;j++){
				if (x[j] >= x[i] - d){
					le = j;
					break;
				}
			}
			for (int j = i;j <= n;j++){
				if (x[j] > x[i] + d){
					ri = j-1;
					break;
				}
			}

			ct[le] += 1;
			ct[i] -= 1;
			ct[i+1] += 1;
			ct[ri+1] -= 1;
		}
		int ans = 0;
		for (int i = 1;i <= n;i++){
			s[i] = s[i-1] + ct[i];
			if (s[i] == 2){
				ans++;
			}
		}
		cout << ans / 2 << endl;
		
	}

	return 0;
}
