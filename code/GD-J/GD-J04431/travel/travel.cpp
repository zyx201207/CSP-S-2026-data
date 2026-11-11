#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string ans = "";
	if(c1 == c2){
		ans += '1';
		string h = "";
		h = h+s1[0]+ s1[1];
		string k = "";
		k = k+s2[0] + s2[1];
		if(h == k){
			ans += '1';
			if (((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || 
			((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))){
				ans += '1';
				if(abs(s1[2]-s2[2]) == 1){
					ans += '1';
				}
				else{
					ans = "1110";
				}
			}
			else{
				ans = "1100";
			}
		}
		else{
			ans = "1000";
		}
	}
	else{
		ans = "0000"; 
	}
	cout<<ans;
	return 0;
}
