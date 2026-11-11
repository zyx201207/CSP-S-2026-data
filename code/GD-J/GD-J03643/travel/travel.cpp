#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

string a,b,s,t;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> s >> t;
	if (a == s){
		cout << 1;
		int paib = (b[0] - '0') * 10 + (b[1] - '0');
		int pait = (t[0] - '0') * 10 + (t[1] - '0');
		if (paib == pait){
			cout << 1;
			char cb = b[2];
			char ct = t[2];
			
			int num = 0;
			if (cb == 'D' || cb == 'F') num++;
			if (ct == 'D' || ct == 'F') num++;
			if (num == 2) cout << "11";
			else if (num == 1) cout << "00";
			else{
				cout << 1;
				if (cb > ct) swap(cb,ct);
				if ((cb == 'A' && ct == 'B') || (cb == 'B' && ct == 'C')) cout << 1;
				else cout << 0;
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	
	
	
	
	
	return 0;
} 
