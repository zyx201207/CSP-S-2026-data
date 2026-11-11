#include <bits/stdc++.h>
using namespace std;
char l[] = {'A','B','C'};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool cok = (c1 == c2);
	bool sok = (cok and s1[0] == s2[0] and s1[1] == s2[1]);
	int f1 = 0,f2 = 0;
	for (char x : l) {
		if (x == s1[2]) f1 = 1;
		if (x == s2[2]) f2 = 1;
	}
	bool siok = (sok and f1 == f2);
	bool nok = false;
	if (s1[2] == 'A' and s2[2] == 'B') nok = true;
	if (s1[2] == 'B' and s2[2] == 'A') nok = true;
	if (s1[2] == 'B' and s2[2] == 'C') nok = true;
	if (s1[2] == 'C' and s2[2] == 'B') nok = true;
	if (s1[2] == 'D' and s2[2] == 'F') nok = true;
	if (s1[2] == 'F' and s2[2] == 'D') nok = true;
	cout << cok << sok << siok << (siok and nok);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
