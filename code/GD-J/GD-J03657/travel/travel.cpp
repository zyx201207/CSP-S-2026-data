#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

string c1,s1,c2,s2;
bool f1,f2,f3;

int main (void) {
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) cout << 1,f1 = true;
	else cout << 0;
	
	for (int i = 0;i <= 1;i++) if (s1[i] != s2[i]) f2 = true;
	if (!f2 and f1) cout << 1;
	else cout << 0;
	
	char p = s1[2],q = s2[2];
	if (!f2 and f1 and ((p >= 'A' and p <= 'C' and q >= 'A' and q <= 'C') or (p >= 'D' and p <= 'F' and q >= 'D' and q <= 'F'))) {
		cout << 1;
		f3 = true;	
	} else cout << 0;
	
	if (f3 and abs(p - q) == 1) cout << 1;
	else cout << 0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
