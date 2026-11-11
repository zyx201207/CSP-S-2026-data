#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll n,d;
ll lis[2222222];
ll nxt[2222222];
ll opt[2222222];

ll clt[2222222];
int num = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 11 or c == 12){
		while(t--){
			cin >> n >> d;
			for(int i = 1;i <= n;i++){
				scanf("%lld",&lis[i]);
			}
			if(n == 1){
				cout << 0 << endl;
			}
			else{
				d = d / (lis[2]-lis[1]);
				if(d == 0 or d == 1){
					cout << 0 << endl;
				}
				else{
					cout << max(0ll,n - 2*d+1) << endl;
				}
			}
		}
	}
	if(c <= 10 or (c >= 15 and c <= 18)){
		while(t--){
			cin >> n >> d;
			int arr = 1;
			for(int i = 1;i <= n;i++){
				scanf("%lld",&lis[i]);
				nxt[i] = 0;
				opt[i] = 0;
			}
			for(int i = 1;i <= n;i++){
				while(arr != n and lis[arr+1]-lis[i] <= d){
					arr += 1;
				}
				nxt[i] = arr;
			}
			ll ans = 0;
			for(int i = 1;i <= n;i++){
				for(int z = 1;z <= num;z++){
					opt[clt[z]] = 0;
				}
				num = 0;
				ll bottom = i;
				ll range = i;
				opt[i] = 1;
				while(range != n and bottom <= range){
					ll alpha = nxt[range];
					ll beta = -1;
					ll gamma = -1;
					if(range-1 >= bottom){
						beta = nxt[range-1];
					}
					if(range-2 >= bottom){
						gamma = nxt[range-2];
					}
					
					ll begin = range;
					ll expire = range;
					if(alpha > range){
						opt[alpha] = min(3ll,opt[range]);
						num += 1;
						clt[num] = alpha;
						if(opt[range] >= 2){
							begin = alpha;
						}
						if(opt[range] >= 3){
							expire = alpha;
						}
					}
					if(alpha-1 > range){
						opt[alpha-1] = min(3ll,opt[range]);
						num += 1;
						clt[num] = alpha-1;
					}
					if(alpha-2 > range){
						opt[alpha-2] = min(3ll,opt[range]);
						num += 1;
						clt[num] = alpha-2;
					}
					if(beta != -1){
						if(beta > range){
							opt[beta] = min(3ll,opt[range]+opt[range-1]);
							num += 1;
							clt[num] = beta;
							if(opt[range]+opt[range-1] >= 2){
								begin = max(begin,beta);
							}
							if(opt[range]+opt[range-1] >= 3){
								expire = max(expire,beta);
							}
						}
						if(beta-1 > range){
							opt[beta-1] = min(3ll,opt[range]+opt[range-1]);
							num += 1;
							clt[num] = beta-1;
						}
						if(beta-2 > range){
							opt[beta-2] = min(3ll,opt[range]+opt[range-1]);
							num += 1;
							clt[num] = beta-2;
						}
					}
					if(gamma != -1){
						if(gamma > range){
							opt[gamma] = min(3ll,opt[range]+opt[range-1]+opt[range-2]);
							num += 1;
							clt[num] = gamma;
							if(opt[range]+opt[range-1]+opt[range-2] >= 2){
								begin = max(begin,gamma);
							}
							if(opt[range]+opt[range-1]+opt[range-2] >= 3){
								expire = max(expire,gamma);
							}
						}
						if(gamma-1 > range){
							opt[gamma-1] = min(3ll,opt[range]+opt[range-1]+opt[range-2]);
							num += 1;
							clt[num] = gamma-1;
						}
						if(gamma-2 > range){
							opt[gamma-2] = min(3ll,opt[range]+opt[range-1]+opt[range-2]);
							num += 1;
							clt[num] = gamma-2;
						}
					}
					ans += begin - expire;
					bottom = range+1;
					range = alpha;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}