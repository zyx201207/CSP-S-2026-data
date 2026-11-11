//GZ-J00254 遵义市新蒲新区白鹭湖小学 韩定远
#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool f1, f2, f3, f4;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) cout << 1;
	else {
		f1 = true;
		cout << 0;
	}
	int t1 = s1[0] - '0', t2 = s2[0] - '0';
	t1 *= 10;
	t2 *= 10;
	t1 = t1 + (s1[1] - '0');
	t2 = t2 + (s2[1] - '0');
	if (f1){
		f2 = true;
		cout << 0;
	} 
	else if (t1 == t2) cout << 1;
	else {
		f2 = true;
		cout << 0;
	}
	int c3 = s1[2], c4 = s2[2];
	if (f2){
		f3 = true;
		cout << 0;
	}
	else if (c3 == 65 && (c4 == 66 || c4 == 67) || c3 == 66 && (c4 == 65 || c4 == 67)|| c3 == 67 && (c4 == 65 || c4 == 66) || c3 == 68 && c4 == 70) cout << 1;
	else {
		f3 = true;
		cout << 0;
	}
	if (f3) cout << 0;
	else if (abs(c3 - c4) == 1){
		if (c3 == 67 || c4 == 67){
			if (c3 == 68 || c4 == 68) cout << 0;
			else cout << 1;
		}
		else cout << 1;
	}
	else if (c3 == 68 && c4 == 70) cout << 1;
	else cout << 0;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
