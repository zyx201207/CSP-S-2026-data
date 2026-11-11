#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int t1, t2;
	int line1, line2;
	char id1, id2;
	cin >> t1 >> line1 >> id1;
	cin >> t2 >> line2 >> id2;
	
	if(t1 == t2){
		cout << '1';
		if(line1 == line2){
			cout <<'1';
			if(id1 == 'A' || id1 == 'B' ||id1 == 'C'){
				if(id2 == 'A' || id2 == 'B' ||id2 == 'C'){
					cout << '1';
					if(abs((id1 - 'A') - (id2 - 'A')) == 1){
						cout <<'1';
					}
					else{
						cout << '0';
					}
				}
				else{
					cout << "00";
				}
			}
			else{
				if(id2 == 'D' || id2 == 'F'){
					cout << "11";
					
				}
				else{
					cout <<	"00";
				}
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout <<"0000";
	}
	return 0;
} 
