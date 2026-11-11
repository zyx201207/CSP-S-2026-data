#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,r1,r2;
	cin >> r1 >> r2 >> x1 >> x2;
	if(r1 == x1){
		cout << "1";
		if(r2[0] == x2[0] && r2[1] == x2[1]){
			cout << "1";
			if(r2[2] == 'A' || r2[2] == 'B' || r2[2] == 'C'){
				if(x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C'){
					cout << "1";
					if(r2[2] == 'A' && x2[2] == 'B') cout << "1";
					else if(r2[2] == 'B' && x2[2] == 'A') cout << "1";
					else if(r2[2] == 'C' && x2[2] == 'B') cout << "1";
					else if(r2[2] == 'B' && x2[2] == 'C') cout << "1";
					else cout << "0";
				}
				else cout << "00";
			}
			else{
				if(r2[2] == 'D' || r2[2] == 'F'){
					cout << "11";
				}
				else cout << "00";
			}
		}
		else cout << "000";
    }
	else cout << "0000";
	return 0;
}
