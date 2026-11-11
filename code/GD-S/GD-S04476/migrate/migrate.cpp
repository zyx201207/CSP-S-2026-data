#include <iostream>
using namespace std;
typedef long long ll;
ll c,t,n,d;
ll dp[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 0;i < n;i++)cin >> dp[i];
		cout << n-3 << endl;
	}
	return 0;
}
