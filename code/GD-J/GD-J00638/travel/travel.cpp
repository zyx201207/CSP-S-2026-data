#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		cout << "1";
		string sub1 = s1.substr(0,2),sub2 = s2.substr(0,2);
		if(sub1 == sub2){
			cout << "1";
			char a = s1[2],b = s2[2];
			ll n = a - 'A',m = b - 'A';
			if(n <= 2 && m >= 3 || m <= 2 && n >= 3){
				cout << "00";
			}else{
				cout << "1";
				ll p = a - 'A',q = b - 'A';
				if(abs(p - q) == 1){
					cout << "1";
				}else cout << "0";
			}
		}else cout << "000"; 
	}else{
		cout << "0000";
	}
	return 0;
}
