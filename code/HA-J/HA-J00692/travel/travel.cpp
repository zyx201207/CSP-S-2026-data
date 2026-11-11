#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int a, b;
char aa, bb;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);	
	cin >> s1 >> a >> aa >> s2 >> b >> bb;
	
	bool flag = 1;
	
	if(s1 == s2){
		cout << 1;
	}else {
		cout << 0;
		flag = 0;
	}
	
	if(a == b && flag){
		cout << 1;
	}else {
		cout << 0;
		flag = 0;
	}
	
	if(flag && ((aa <= 'C' && bb <= 'C') || (aa >= 'D' && bb >= 'D'))) {
		cout << 1;
	}
	else flag = 0, cout << 0;
	
	if(flag && abs((int)aa - (int)bb) <= 1 && !((aa == 'C' && b == 'D') || (aa == 'D' && b == 'C'))) cout << 1;
	else cout << 0;
	
	return 0;
}
