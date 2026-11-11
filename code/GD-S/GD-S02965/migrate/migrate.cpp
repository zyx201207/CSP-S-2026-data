#include <bits/stdc++.h>
using namespace std;
long long c , t , n , d , x[2000005] , f[5005][5005] , sum , sum1 , l , r , lr[2000005] , rr[2000005] , ls , rs , ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(long long i = 1 ; i <= t ; i ++){
		memset(x , 0 , sizeof(x));
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i ++){
			cin >> x[i];
		}
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i + 1 ; j <= n ; j ++){
				ans = 0;
				l = i , ls = 1;
				r = j , rs = 1;
				memset(lr , 0 , sizeof(lr));
				memset(rr , 0 , sizeof(rr));
				while(l <= j){
					if(l >= j){
						if(ls == rs){
							for(int i = 1 ; i <= ls ; i ++){
								if(lr[i] != rr[ls + 1 - i]){
									ans ++;
									break;
								}
							}
							break;
						}
					}
					if(x[l + 1] - x[l] + sum > d){
						sum = 0;
						lr[ls] = l;
						ls ++;
					}
					if(x[r] - x[r - 1] + sum1 > d){
						sum1 = 0;
						rr[rs] = r;
						rs ++;
					}
					sum += x[l + 1] - x[l];
					sum1 += x[r] - x[r - 1];
					l ++;
					r --;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdin);
	return 0;
}
