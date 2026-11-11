#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    bool flag1 = 1, flag2 = 0, flag3 = 0, flag4 = 0;
    cin >> c1;
    cin >> s1;
    cin >> c2;
    cin >> s2;
    if (c1 != c2){
		flag1 = 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]){
		flag2 = 1;
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			flag3 = 1;     
	    }
	}else{
		if (s2[2] == 'D' || s2[2] == 'F'){
			flag3 = 1;     
	    }
	}
	if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')){
		flag4 = 0;
	}else{
		if (abs(s1[2] - s2[2]) == 1){
			flag4 = 1;
	    }
	}
	if (flag1) cout << 1;
	else cout << 0;
	if (flag1 && flag2) cout << 1;
	else cout << 0;
	if (flag1 && flag2 && flag3) cout << 1;
	else cout << 0;
	if (flag1 && flag2 && flag3 && flag4) cout << 1;
	else cout << 0;
	    
    return 0;
}
