#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int a,b;
	string s1,s2;
	cin >> a >> s1 >> b >> s2;
	
	int num1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int num2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	
	char ch1 = s1[2],ch2 = s2[2];
	if(a != b) {
		cout << "0000" << endl;
	}
	else if(num1 != num2){
		cout << "1000" << endl;
	}
	else if((ch1 <= 'C' && ch2 > 'C') || (ch2 <= 'C' && ch1 > 'C')){
		cout << "1100" << endl;
	}
	else if((abs(ch1-ch2) == 1) || ((ch1 == 'F' || ch2 == 'F') && abs(ch1-ch2) == 2)){
		cout << "1111" << endl;
	}
	else cout << "1110" << endl;
	return 0;
}
