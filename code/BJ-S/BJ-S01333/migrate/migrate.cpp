#include <cstring>
#include <iostream>
using namespace std;
#define int long long 

int coord[5005];
int ct[5005];
int fminv[5005];

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin>>c>>T;
	while(T--){
		memset(coord, 0x00, sizeof(coord));
		int n, d;
		cin>>n>>d;
		for(int i = 1; i <= n; i ++){
			cin>>coord[i];
		}
		int res = 0;
		for(int i = 1; i <= n; i ++){
			memset(ct, 0x00, sizeof(ct));
			memset(fminv, 0x3f, sizeof(fminv));
			fminv[i] = 0;
			ct[i] = 1;
			for(int j = i; j <= n; j ++){
				if(ct[j] == 2) res ++;
				for(int k = j; coord[k] - coord[j] <= d && k <= n; k ++){
					if(fminv[k] < fminv[j] + 1) continue;
					if(fminv[k] == fminv[j] + 1) ct[k] += ct[j];
					else fminv[k] = fminv[j] + 1, ct[k] = ct[j];
				}
			}
		}
		cout<<res<<endl;
	}
}
