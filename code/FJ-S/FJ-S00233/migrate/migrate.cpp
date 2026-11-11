#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for (int i = j;i <= k;i++)
typedef long long ll;
ll c,t,n,d;
ll arr[2000005];
ll delta,k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
        rep(i,1,n) cin >> arr[i];
        if (n>1) {
        	delta = (arr[n]-arr[1])/(n-1);
        	k = d/delta;
        	if (k >= 2 && k <= n-1){
        		cout << n-(2*k-1)<<"\n"; 
			}
			else {
				cout <<"0\n";
			}
		}
        else{
        	cout << "0\n";
		}
		//cout << "delta:"<<delta<<" "<<"n:"<<n<<" d:"<<d<<"\n"<<"k:"<<k<<"\n";
		
	}
	return 0;
}
