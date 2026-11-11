#include<bits/stdc++.h>
using namespace std;
int c1, c2, a[5];
string s1, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		a[1] = 1;
		int num1 = s1[0] * 10 + s1[1], num2 = s2[0] * 10 + s2[1];
		if (num1 == num2){
			a[2] = 1;
			if (s1[2] == 'A'){
				if (s2[2] == 'B')
					a[3] = a[4] = 1;
				if (s2[2] == 'C')
					a[3] = 1;
			}
			if (s1[2] == 'B'){
				if (s2[2] == 'A')
					a[3] = a[4] = 1;
				if (s2[2] == 'C')
					a[3] = a[4] = 1;
			}
			if (s1[2] == 'C'){
				if (s2[2] == 'B')
					a[3] = a[4] = 1;
				if (s2[2] == 'A')
					a[3] = 1;
			}
			if (s1[2] == 'D')
				if (s2[2] == 'F')
					a[3] = a[4] = 1;
			if (s1[2] == 'F')
				if (s2[2] == 'D')
					a[3] = a[4] = 1;
		}
	}
	cout << a[1] << a[2] << a[3] << a[4];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//a b c
//d f
