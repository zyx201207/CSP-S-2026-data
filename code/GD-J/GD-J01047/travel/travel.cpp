#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,s1,s2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> n >> s1 >> a >> m >> s2 >> b;
//	cout << n << endl << s1 << endl << a << endl << m << endl << s2 << endl << b;
	if (n != m){
		cout << "0000";
		return 0;
	}if (s1 != s2){
		cout << "1000";
		return 0;
	}if (!((a >= 'D' && b >= 'D') || (a <= 'C' && b <= 'C'))){
		cout << "1100";
		return 0;
	}if (abs(ll(a - b)) != 1){
		cout << "1110";
		return 0;
	}cout << "1111";
	return 0;
}
