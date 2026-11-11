#include <bits/stdc++.h> 
using namespace std;
int main(){
	//freopen("travel.in","r", stdin);
	//freopen("travel.out","w", stdout);
	string c, s, cc, ss;
	cin >> c >> s >> cc >> ss;
	string ans;
	if(c == cc) ans += '1';
	else{
	ans = "0000"; // 不在同一节车厢 
	cout << ans;
	return 0;
}
	if(ss[0] == s[0] && ss[1] == s[1]) ans += '1';
	else ans += "00";
	bool ok = true;
	if(((ss[2] >= 'A' && ss[2] <= 'C') && (s[2] >= 'A' && s[2] <= 'C')) || (ss[2] >= 'D' && ss[2] <= 'E' && s[2] >= 'D' && s[2] <= 'E')){
		if(ans == "11") ans += '1';
	} 
	else { ok = false; ans += '0'; }
	int data0 = 0, data1 = 0, p = 1;
    for(int i = 1; i >= 0; i--){
           data0 += (s[i] - '0') * p;
           data1 += (ss[i] - '0') * p;
           p *= 10;
}
      if((abs(data0 - data1) == 1 && abs((s[2] - 'A') - (ss[2] - 'A')) == 0) || (abs(data0 - data1) == 0 && abs((s[2] - 'A') - (ss[2] - 'A')) == 1) && ok) ans += '1';
      else ans += '0';
      cout << ans;
	  return 0;
}
