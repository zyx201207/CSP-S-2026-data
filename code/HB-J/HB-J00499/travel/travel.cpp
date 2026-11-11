#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
string ans="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2){
		ans="1000";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			ans="1100";
			char a1=s1[2];
			char a2=s2[2];
			if(  ( a1 <= 'C' && a2 <= 'C' ) || ( a1 >= 'D' && a2 >= 'D')  ){
				ans="1110";
				if(abs(a1 - a2) == 1){
					ans="1111";
				}
			}
		}
	}
	cout << ans;
	return 0;
}
