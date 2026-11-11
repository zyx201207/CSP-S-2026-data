#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
	ll minn;
	ll cnt;
}b[200006];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);  
	ll c,T;             
	cin >> c >> T;
	while ( T -- ) {
		ll n , d, ans=0;
		cin >> n >> d;
		ll a[200006];
		cin >> a[1];
		for (ll i = 2; i <= n; i++) {
			cin >> a[i];
			if (a[1] < 0) a[i] += 1-a[1];
		}
		for(int s=1;s<=n;s++){
//			cout <<"s:"<<s<<"  ----------------------------"<<endl;
			
			for (ll k = s;k <= n; k++) {
				b[k].minn=9999999;
			}
			b[s].cnt=0;
			b[s].minn=0;
			for (ll i = s+1; i <= n; i++) {
//				cout << "i:"<<i<<endl;
				ll j = i-1;
				while (j >= s) {
				
					if (a[i] - a[j] <= d) {
						if (b[j].minn + 1 < b[i].minn ) {
							b[i].minn = b[j].minn + 1;
//							cout <<1;
							b[i].cnt = 1;
						}else if(b[j].minn + 1 == b[i].minn) {
							b[i].cnt += 1;
						}
//						cout<<"yesj:"<<j<<"  b[i].cnt:"<<b[i].cnt<< endl;
					}else{
//					cout<<"noj:"<<j<<endl;
						break; 
					}
					j--;
				}
				if(b[i].cnt==2) ans++;
			}
		}
		cout<<ans<<"\n"; 
	}                                                                                                                                                                                                                                                                                                                                                                                           
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
