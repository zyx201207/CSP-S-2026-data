#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
bool f = 0,k = 0,l = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	if(a[0] == c[0] && a[1] == c[1]){
		cout << 1;
		k = 1;
	}
	else
		cout << 0;
	if(k == 0){
		cout << 0 << 0 << 0; 
		return 0;
	}
		
	
	if(b[0] == d[0] && b[1] == d[1] && k){
		cout << 1;
		l = 1;
	}
	else
		cout << 0;
	if(l == 0){
		cout << 0 << 0;
		return 0;
	}
	
	
	if(b[2] == 'C' && d[2] == 'D')
		cout << 0;
	else
		if(b[2] == 'D' && d[2] == 'C')
			cout << 0;
		else
			if(l&&k){
				cout << 1;
				f = 1;
			}
			else
				cout << 0;
	if(f == 0){
		cout << 0;
		return 0;
	}
	
	
	if((b[2] - d[2] == 1||d[2]-b[2] == 1 || (b[2] == 'F'&&d[2] == 'D') || (b[2] == 'D'&&d[2] == 'F'))&&f&&k&&l)
		cout << 1;
	else
		cout << 0;
	//cout << '\n' << k << l << f;
	return 0;
} 
