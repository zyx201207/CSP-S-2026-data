#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a,b;
	string A,B;
	
	cin >> a >> A >> b >> B;
	
	char ac = A[2],bc = B[2];
	int ai = ac,bi = bc; 
	
	if(a == b) {
		cout << "1";
		if(A[0] == B[0] && A[1] == B[1]) {
			cout << "1";
			if(ai <= 67 && bi <= 67){
				cout << "1";
				if(abs(ai-bi) == 1)
					cout << "1";
				else cout << "0";
			}
			else if(ai > 67 && bi < 67) cout << "11";
			else cout << "00";
		}
		else cout << "000"; 
	}
	else cout << "0000";
	
	cout << endl;
	return 0;
} 
