#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aa,bb,ap = "",bp = "";
	char al,bl;
	int l = 0,d = 0;
	cin >> a >> aa >> b >> bb;
	if (a != b){
		cout << "0000";
	}else{
		for (int i = 0;i < 2;i++){
			ap += aa[i];
			bp += bb[i];
		}
		if (ap != bp){
			cout << "1000";
			return 0;
		}
		al = aa[2];
		bl = bb[2];
		if (al == 'D' || al == 'F'){
			l += 1;
		}
		if (bl == 'D' || bl == 'F'){
			l += 1;
		}
		if (l == 1){
			cout << "1100";
			return 0;
		}
		if (al != 'B'&& bl != 'B'){
			cout << "1110";
		}else{
			cout << "1111"<< endl;
		}	
	}
	return 0;
}
