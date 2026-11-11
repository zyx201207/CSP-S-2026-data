#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e2 + 5;

//travel

string c1,s1,c2,s2;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c1 >> s1 >> c2 >> s2;
	char a = '0',b = '0',c = '0',d ='0';
	
	if(c1 == c2) {
		a = '1';
		int p_1 = (s1[0] - '0') * 10 + (s1[1] - '0');
		int p_2 = (s2[0] - '0') * 10 + (s2[1] - '0');
		if(p_1 == p_2) {
			b = '1';
			if((s1[2] >= 'A' and s1[2] <= 'C' and s2[2] >= 'A' and s2[2] <= 'C') or (s1[2] >= 'D' and s1[2] <= 'F' and s2[2] >= 'D' and s2[2] <= 'F')) {
				c = '1';
				if(abs((s1[2] - 'A') - (s2[2] - 'A')) == 1) {
					d = '1';
				}
			}
		}
	}
	cout << a << b << c << d; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

