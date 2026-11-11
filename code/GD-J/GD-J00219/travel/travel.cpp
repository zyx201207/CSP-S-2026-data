#include <bits/stdc++.h>
using namespace std;
int chexiang1, chexiang2;
int pai1, pai2;
char zuo1, zuo2;
int main(){
	 freopen("travel.in", "r", stdin);
	 freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> chexiang1 >> pai1 >> zuo1;
	cin >> chexiang2 >> pai2 >> zuo2;
	
	if(chexiang1 == chexiang2){
		cout << "1";
		if(pai1 == pai2){
			cout << "1";
			if((zuo1 <= 'C' && zuo2 <= 'C') || (zuo1 >= 'D' && zuo2 >= 'D')){
				cout << "1";
				if(char(zuo1 + 1) == zuo2 || char(zuo2 + 1) == zuo1){
					cout << "1\n";
				}
				else{
					cout << "0\n";
				}
			}
			else{
				cout << "00\n";
			}
		}
		else{
			cout << "000\n";
		}
	}
	else{
		cout << "0000\n";
	}
	
	return 0;
}
