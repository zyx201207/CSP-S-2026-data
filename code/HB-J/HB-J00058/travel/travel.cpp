#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;
int b[4];
char d[5] = {'B', 'C', '!', 'F', '!'};

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	memset(b, 0, sizeof(b));
	if (c1 == c2){
		b[0] = 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			b[1] = 1;
			if (!((s1[2] <= 'C') ^ (s2[2] <= 'C'))){
				b[2] = 1;
				if (d[s2[2] - 'A'] == s1[2] || d[s1[2] - 'A'] == s2[2])
					b[3] = 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		cout << b[i];
	cout << endl;
	return 0;
}