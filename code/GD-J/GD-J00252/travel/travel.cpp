#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;	
string c1, s1, c2, s2;
string ans;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans += "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans += "1";
			if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))){
				ans += "1";
				char x = s1[2], y = s2[2];
				if(((x == 'D' || x == 'F') && (y == 'D' || y == 'F'))){
					ans += "1";
				}
				else{
					if(x > y)
						swap(x, y);
					if(x - 'A' + 'B' == y)
						ans += "1";
				}
			}
		}
	}
	cout << ans;
	for(int i = 1; i <= 4 - ans.size(); i++){
		cout << 0;
	}
	return 0;
}
