#include<bits/stdc++.h>
using namespace std;

int car1, car2;
string s1, s2;
int row1, row2;
char col1, col2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin>>car1>>s1;
	cin>>car2>>s2;
	row1 = stoi(s1.substr(0, 2)); col1 = s1[2];
	row2 = stoi(s2.substr(0, 2)); col2 = s2[2];
//	cout<<car1<<' '<<row1<<" "<<col1<<endl;
//	cout<<car2<<' '<<row2<<" "<<col2<<endl;
	
	if(car1 == car2){
		if(row1 == row2){
			bool b1 = (col1=='A'||col1=='B'||col1=='C') && (col2=='A'||col2=='B'||col2=='C');
			bool b2 = (col1=='D'||col1=='F') && (col2=='D'||col2=='F');
			if(b1 || b2){
				if(abs(col1 - col2) == 1){
					cout<<"1111";
				} else {
					cout<<"1110";
				}
			} else {
				cout<<"1100";
			}
		} else {
			cout<<"1000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
