#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdout);
	freopen("travel.out","w",stdin);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string ans[4] = {"0","0","0","0"};
	if (c1 == c2){
		ans[0] = "1";
		if ((s1[1] == s2[1])&&(s1[0] == s2[0])){
			ans[1] = "1";			
		}
	}
	cout << ans[0] << ans[1] << ans[2] << ans[3];
	return 0;
}
