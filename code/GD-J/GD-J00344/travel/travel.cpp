#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	string ans = "";
	if(c1 == c2){
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			int a = s1[2] - 'A' + 1;
			int b = s2[2] - 'A' + 1;
			if((a >= 1 && a <= 3 && b >= 1 && b <= 3) || (a >= 4 && a <= 5 && b >= 4 && b <= 5)){
				if(abs(a - b) == 1){
					ans = "1111";
				}else{
					ans = "1110";
				}
			}else{
				ans = "1100";
			}
		}else{
			ans = "1000";
		}
	}
	else{
		ans = "0000";
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
