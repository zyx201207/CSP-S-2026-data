#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
char e,f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("traval.out","w",stdout);
	cin >> a >> b >> e >> c >> d >> f;
	if(a != c || a == 1 || a == 16) cout << "0000";
	else{
		if(b != d) cout << "1000";
		else{
			if(((e == 'A' || e == 'B' || e == 'C') && (f == 'D' || f == 'E')) || ((f == 'A' || f == 'B' || f == 'C') && (e == 'D' || e == 'E'))) cout << "1100";
			else{
				if(abs((int)e - (int)f) > 1) cout << "1110";
				else cout << "1111";
			}
		}
	}
	return 0;
}
