#include <iostream>
using namespace std;

typedef long long ll;
const ll N=500005;
ll n,m,a[N],table_[N],ans[N]={0};
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			bool flag=false;
			for(ll k=1;k<=n;k++){
				if(table_[k] == a[j]){
					flag = true;
				}
				if(!(flag)){
					ans[j]++;
				}
			}
			table_[j] = a[j];
		}
	}
	for(ll i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

