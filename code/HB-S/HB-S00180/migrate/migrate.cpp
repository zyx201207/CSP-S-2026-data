#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		dp[1]=1;
		for(int i=1;i<=n;i++){
			cin >> d;
		}
		cout << 1 endl;
	}
	return 0;
}
