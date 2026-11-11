#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;

int a[N];
int f[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, d, ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];	
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)f[j] = 0;
			
			ll l = i, sum = 1;
			f[i] = 1;
			for(int j = i + 1; j <= n; j++){
				while(a[j] - a[l] > d){
					sum -= f[j];
					j++;
				}	
				f[j] = sum;
				//cout << f[j] << " ";
				if(f[j] == 2)ans++;
				sum += f[j];
			}
			//cout << '\n';	
		}
		
		cout << ans - 1 << '\n';
	}
}
