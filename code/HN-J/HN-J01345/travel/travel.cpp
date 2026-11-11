#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
#define __low lower_bound
#define __upp upper_bound
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

string s1, s2, t1, t2;

int get(char c){
	if(c <= 'C') return 0;
	return 1;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin >> s1 >> s2 >> t1 >> t2;
	if(s1 != t1){
		cout << "0000\n";
	} else{
		cout << "1";
		if(s2[0] != t2[0] || s2[1] != t2[1]){
			cout << "000\n";
		} else{
			cout << "1";
			if(get(s2[2]) != get(t2[2])){
				cout << "00\n";
			} else{
				cout << "1";
				if(abs(s2[2] - t2[2]) == 1){
					cout << "1\n";
				} else{
					cout << "0\n";
				}
			}
		}
	}
	
	return 0;
}
