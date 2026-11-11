#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	int cc1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	int cc2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	if (cc1 == cc2){
		ans1 = 1;
	}
	int p1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int p2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if ((p1 == p2) && ans1){
		ans2 = 1;
	}
	char seat1 = s1[2],seat2 = s2[2];
	bool df = false;
	if (ans2){
		if (seat1 == 'A'){
			if (seat2 == 'B' || seat2 == 'C'){
				ans3 = 1;
			}
		}
		if (seat1 == 'B'){
			if (seat2 == 'A' || seat2 == 'C'){
				ans3 = 1;
			}
		}
		if (seat1 == 'C'){
			if (seat2 == 'B' || seat2 == 'A'){
				ans3 = 1;
			}
		}
		if (seat1 == 'D' && seat2 == 'F'){
			ans3 = 1;
			df = true;
		}
		if (seat1 == 'F' && seat2 == 'D'){
			ans3 = 1;
			df = true;
		}
	}
	if (ans3){
		if (df){
			ans4 = 1;
		}
		if (seat1 == 'A' || seat1 == 'C'){
			if (seat2 == 'B'){
				ans4 = 1;
			}
		}
		if (seat1 == 'B'){
			if (seat2 == 'A' || seat2 == 'C'){
				ans4 = 1;
			}
		}
	}
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
} 
