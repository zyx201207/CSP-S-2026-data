#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c) {
		cnt++;cout << 1;
		if(b[0] == d[0] && b[1] == d[1]){
			cnt ++;cout << 1;
			if(b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C'){
				cnt++;cout << 1;
				if(abs(b[2] - d[2]) == 1) {
					cnt++;cout << 1;
				}
			}
		}
	}
	for(int i = cnt; i < 4; i++) cout << 0;
	return 0;
}