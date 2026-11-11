#include <bits/stdc++.h>
using namespace std;

string c1, c2, a1, a2;

char d1[] = {'A', 'B', 'D'};
char d2[] = {'B', 'C', 'F'};

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> a1 >> c2 >> a2;
	if(c1 == c2){
		cout << "1";
		if(a1.substr(0, 2) == a2.substr(0, 2)){
			cout << "1";
			char q = a1[2], p = a2[2];
			if(q <= p)swap(q, p);
			for(int i = 0; i < 3; i++){
				if(p == d1[i] && q == d2[i]){
					cout << "11";
					return 0;
				}
			}
			if(p == 'A' && q == 'C'){
				cout << "10";
				return 0;
			}
			cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	
	
	return 0;
} 
