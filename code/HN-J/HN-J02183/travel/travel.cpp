#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xiang1,xiang2,pai1,pai2;
	cin >> xiang1 >> pai1;
	cin >> xiang2 >> pai2;
	if (xiang1 == xiang2){
		cout << '1';
		if (pai1[0]==pai2[0]&&pai1[1]==pai2[1]){
			cout << '1';
			if (pai1[2]-pai2[2] <= 2){
				if((pai1[2] == 'C'&&pai2[2] == 'D')||(pai2[2] == 'C'&&pai1[2] == 'D')){
					cout << "00";
					return 0;
				}
				if((pai1[2] == 'C'&&pai2[2] == 'F')||(pai2[2] == 'C'&&pai1[2] == 'F')){
					cout << "00";
					return 0;
				}
				if((pai1[2] == 'B'&&pai2[2] == 'D')||(pai2[2] == 'B'&&pai1[2] == 'D')){
					cout << "00";
					return 0;
				}
				if((pai1[2] == 'F'&&pai2[2] == 'D')||(pai2[2] == 'F'&&pai1[2] == 'D')){
					cout << "11";
					return 0;
				}
				cout << '1';
				if (pai1[2]-pai2[2] == 1||pai1[2]-pai2[2] == -1){
					cout << '1';
					return 0;
				}
				cout << '0';
				}
				else
				{
				cout << "00";
				}
			}
		else 
		{
		cout << "000";
		}
	}
	else 
	{
		cout << "0000";
	}
	return 0;
} 
