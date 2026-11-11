#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string c1, c2, s1, s2;//c1:小R的车厢号 c2:小X的车厢号 s1:小R的座位号 s2:小X的座位号
	string ans = "0000";//ans:答案的字符串 
	bool flag = false, f1 = false, f2 = false;//flag:是否位于同一节车厢的同一排  f1:是否位于同一侧  
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2)ans[0] = '1';
	else ans[0] = '0';
	
	if(s1[0] == s2[0] && s1[1] == s2[1] && c1 == c2){
		flag = true;
		ans[1] = '1';
	}
	else ans[1] = '0';
	
	if(flag){
		if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
			if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
				f1 = true;
				ans[2] = '1';
			}
			else ans[2] = '0';
		}else {
			if(s2[2] == 'D' || s2[2] == 'F'){
				f1 = true;
				ans[2] = '1';
			}
			else ans[2] = '0';
		}
	}else ans[2] = '0';
	
	if(f1){
		if(abs(int(s1[2] - s2[2])) == 1)ans[3] = '1';
		else ans[3] = '0';
	}else ans[3] = '0';
	
	cout << ans;
	
	return 0;
} 
