#include <bits/stdc++.h>
using namespace std;


bool check2(string s,string t){
	for(int i = 0;i <= 1;i ++)if(s[i] != t[i])return false;
	return true; 
} 
bool check3(string s,string t){
	if(s[2] <= 'C' && t[2] <= 'C' || s[2] > 'C' && t[2] > 'C')return true;
	return false; 
} 
bool check4(string s,string t){
	return abs(s[2] - t[2]) == 1;
} 
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,zw1;cin >> cx1 >> zw1;
	string cx2,zw2;cin >> cx2 >> zw2;
	bool ans1 = cx1 == cx2; // 同一车厢 
	bool ans2 = ans1 && check2(zw1,zw2); // 同一排
	bool ans3 = ans2 && check3(zw1,zw2); // 同一侧
	bool ans4 = ans3 && check4(zw1,zw2); // 相邻  
	cout << ans1 << ans2 << ans3 << ans4 << '\n'; 
	return 0;
} 
