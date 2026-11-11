//GZ-J00546 遵义周林学校 杨莒粞  
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()  {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string car,seat,ccar,sseat;
	cin >> car >> seat >> ccar >> sseat;
	if (car == ccar) {
		cout << "1";
		if (seat[0] == sseat[0] && seat[1] == sseat[1]) {
			cout << "1";
			if (seat[2] >= 'D' && sseat[2] >= 'D') 
			  cout << "11";
			else if (seat[2] <= 'C' && sseat[2] <= 'C') {
				cout << "1";
				if (seat[2] + 1 == sseat[2] || sseat[2] + 1 == seat[2]) {
					cout << "1";
				} else 
				  cout << "0";
			} else {
				cout << "00";
			}
		} else 
		  cout << "000";
	} 
	else 
	 cout << "0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
