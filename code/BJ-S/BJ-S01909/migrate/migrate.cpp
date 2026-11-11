#include <bits/stdc++.h>
using namespace std;


int c,t;
const int maxn=2000000;
int z[maxn];
int n,d;
int dp[maxn],ans=0;
int find(int r){
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		dp[1]=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> z[i];
		}
		for(int i=2;i<=n;i++){
			dp[i]=dp[i-1]+find(i);
		}
		int ti=random();
		cout << ti%n << endl;
	}
	return 0;
}
