#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string seat1, seat2;
    int tra1, tra2;
    cin >> tra1 >> seat1 >> tra2 >> seat2;
    if(tra1 == tra2){
		cout << '1';
		if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
			cout << '1';
		    if(seat1[2] == 'D' || seat1[2] == 'E'){
				if(seat2[2] != 'D' || seat2[2] != 'E'){
					cout << "00";
				}else{
					cout << "11";
				}
			}else{
				if(seat2[2] == 'D' || seat2[2] == 'E'){
					cout << "00";
				}else{
					cout << '1';
					if(seat1[2] == 'B'){
						cout << '1';
					}else{
						if(seat2[2] == 'B'){
							cout << '1';
						}else{
							cout << '0';
						}
					}
				}
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}

    return 0;
}
