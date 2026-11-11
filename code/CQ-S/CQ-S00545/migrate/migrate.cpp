#include<bits/stdc++.h>
#define ll long long
using namespace std;
int testcase,T;
int n;
ll d;
const int maxn = 2e6 + 10;
ll x[maxn];
//
void testSix(){
	while(T--){
		//Bruteforce
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n == 1){
			cout<<0<<'\n';
			continue;
		}
		ll D = x[2] - x[1];
		ll k = d / D;
		if(k <= 1){
			cout<<0<<'\n';
			continue;
		}
		cout<<max(0ll,(ll)n-k*2+1)<<'\n';;
//		if(d >= 2 * D && d < 3 * D){
//			cout<<max(0,n-3)<<'\n';
//		}else cout<<0<<'\n';
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>testcase>>T;
	if(testcase == 11 || testcase == 12) testSix();
	return 0;
}
/*

*/
