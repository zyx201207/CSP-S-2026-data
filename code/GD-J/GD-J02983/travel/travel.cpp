#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	int c1, s1, c2, s2;
	char ch1, ch2;
	cin >> c1 >> s1 >> ch1 >> c2 >> s2 >> ch2;
	if(c1 == c2){
		cout << 1;
		if(s1 == s2){
			cout << 1;
			if(ch1 <= 'C' && ch2 <= 'C' || ch1 >= 'D' && ch2 >= 'D'){
				cout << 1;
				if(min(ch1, ch2) + 1 == max(ch1, ch2)){
					cout << 1;
				} 
				else{
					cout << 0;
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
}
