#include <bits/stdc++.h>

using namespace std;

long long c,t;
long long n,d;
long long a[2000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	
	cin >> c >> t;
	while(t--){
		long long k = 2e6 + 5;
		bool flag = false;
		cin >> n >> d;
		if(d == 1){
			cout << 0;
			continue; 
		}
			
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			if(!flag and i > 1 and a[i] - a[i - 1] > d)
				k = i,flag = true;
		}
		--k;
		long long cnt = 0;
		for(int i = 1;i <= n;i++){
			for(int len = 4;len + i - 1 <= min(n,k);len++){
				long long wid = a[i + len - 1] - a[i];
				if(wid & 1 and wid % d != 0){
					//cout <<"^^^"<< i <<" " << len<<'\n';
					cnt++;
				}
			}
		}
		cout << cnt <<'\n';
	}
	return 0;
} 
