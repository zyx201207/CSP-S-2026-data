#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
long long a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n;
		long long d;
		cin >> n >> d;
		int xx = 0;
		bool cc = 1;
		for(int j=1;j<=n;j++){
			cin >> a[j];
			if(j==2){
				xx = a[j] - a[j-1];
			}
			if(j>=3){
				if(a[j] - a[j-1] != xx){
					cc = 0;
				}
			}
		}
		if(cc == 1){
			cout << 0 << '\n';
		}
		else{
			cout << 1 << '\n';
		}
	}
	return 0;
}
