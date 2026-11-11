#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cc;
	string s,ss;
	cin >> c >> s >> cc >> ss;
	if(c == cc){
		cout << "1";
		if(s[0]*10+s[1] == ss[0]*10+ss[1]){
			cout << "1";
			if((s[3] <= 'C' && ss[2] <= 'C') || (s[3] > 'C' && ss[2] > 'C')){
				cout << "1";
				if(abs(int(s[2]) - int(ss[2])) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
}
