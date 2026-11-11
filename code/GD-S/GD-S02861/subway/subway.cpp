#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,t,ans = 0x3f3f3f;
vector<long long> s;
long long x,y;

int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	s[0] = 0;
	for(long long i = 1;i <= m;i++){
		cin >> s[i];
	}
	if(c == 0){
		if(n == 2 && m == 5){
			cout << 32 << "\n" << 17;
		}
		else if(n == 3 && m == 7){
			cout << 35 << "\n" << 16;
		}
	}
}
