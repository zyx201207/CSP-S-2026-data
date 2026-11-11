#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c)
	{
		cout << "1";
		if(b[0] == d[0] && b[1] == d[1]){
			cout << "1";
			char s1 = min(b[3],d[3]),s2 = max(b[3],d[3]);
			if(s1 >= 'D' || s2 <= 'C'){
				cout << "1";
				if(s1 - s2 <= 1){
					cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
}
