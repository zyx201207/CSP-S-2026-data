#include <bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> s >> cc >> ss;
	a=s[2]-'A';
	b=ss[2]-'A';
	if (c==cc){
		cout << 1;
		if (s[0]==ss[0]&&s[1]==ss[1]){
			cout << 1;
			if (a<=2&&b<=2){
				cout << 1;
				if (abs(a-b)==1)cout << 1;
				else cout << 0;
			}
			else if (a>=3&&b>=3){
				cout << 1;
				if (abs(a-b)==1)cout << 1;
				else cout << 0;
			}
			else cout <<"00";
		}
		else cout<<"000";
	}
	else cout << "0000";
	return 0;
} 
