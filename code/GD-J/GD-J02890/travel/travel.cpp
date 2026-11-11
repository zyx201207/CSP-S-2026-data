#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
	string r1,t1;
	char r2,t2;
	if (c1 == c2) {
		ans1 = 1;
		for (int i = 0;i < 2;i++) r1 += s1[i]; 
		for (int i = 0;i < 2;i++) t1 += s2[i];
		for (int i = 2;i < 3;i++) r2 += s1[i]; 
		for (int i = 2;i < 3;i++) t2 += s2[i];
		if (r1 == t1) {
			ans2 = 1;
			if (r2 <= 'C' && t2 <= 'C'){
				ans3 = 1;
				if (abs(r2 - t2) == 1)ans4 = 1;	}
			if (r2 > 'C' && t2 > 'C'){
				ans3 = 1;
				if (abs(r2 - t2) == 2) ans4 = 1;}}}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;}
