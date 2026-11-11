#include <bits/stdc++.h>
using namespace std;

string a,b,n,m,ans;
bool x = 1; 

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> n >> b >> m;
	
			if((a[0] == b[0] && a[1] == b[1])&&x) ans = ans + '1';
			else {
				ans = ans + '0';
				x = 0;
			}
			if((n[0] == m[0] && n[1] == m[1])&&x) ans = ans + '1';
			else{
				ans = ans + '0';
				x = 0;
			}
			if(((n[2]<='C'&&m[2]<='C')||(n[2]>'C'&&m[2]>'C'))&&x) ans = ans + '1';
			else{
				ans = ans + '0';
				x = 0;
			}
			if(((n[2]+1==m[2])||(n[2]-1==m[2]))&&x) ans = ans + '1';
			else{
				ans = ans + '0';
				x = 0;
			}
	
	cout << ans;
	
	return 0;
} 
