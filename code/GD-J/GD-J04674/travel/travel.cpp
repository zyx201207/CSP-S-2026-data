#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string c1,s1,c2,s2;

ll if_3(string x){
	if(x[2] <= 'C') return 1;
	else return 2;
}

ll if_4(string x){
	if(x[2] <= 'C') return x[2]-'A'+1;
	else return x[2]-'A'+2; 
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;//R:c1,s1    X:c2,s2
	
	if(c1 == c2){
		cout << '1';
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << '1';
			if(if_3(s1) == if_3(s2)){
				cout << '1';
				
				ll tmp = abs(if_4(s1) - if_4(s2));
				if(tmp == 1) cout << '1';
				else cout << '0'; 
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	
	
	return 0;
} 
