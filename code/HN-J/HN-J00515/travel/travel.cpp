#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,st,s2,ss;
	cin >> s1 >> st >> s2 >> ss;
	if(s1 == s2){
		cout << "1";
	}else{
		cout << "0";
	}
	string s3 = st.substr(0,2),s4 = ss.substr(0,2);
	if(s1 == s2 && s3 == s4){
		cout << "1";
	}else{
		cout << "0";
	}
	string s5 = st.substr(2,1),s6 = ss.substr(2,1);
	bool tf = false;
	if(s5 <= "C"){
		if(s6 <= "C"){
			tf = true;
		}
	}
	if(s5 <= "F"){
		if(s6 <= "F"){
			tf = true;
		}
	}
	if(s1 == s2 && s3 == s4 && tf){
		cout << "1";
	}else{
		cout << "0";
	}
	if((s5 == "A" && s6 == "B") || (s5 == "B" && (s6 == "A" || s6 == "C")) || (s5 == "C" && s6 == "B") || (s5 == "D" && s6 == "F") || (s5 == "F" && s6 == "D")){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
