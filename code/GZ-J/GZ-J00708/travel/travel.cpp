//李泽瑞 GZ-J00708
#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string s1;
	string s2;
	string s3;
	string s4;
	cin >> s1 >> s2 >> s3 >> s4;
	string ans;
	if(s1 == s3){
		ans.push_back('1');
		//cout << "在同一节车厢" << endl; 
	}else{
		ans.push_back('0');
		//cout << "不在同一节车厢" << endl;
	}
	if(s1 == s3 && s2[1] == s4[1] && s2[0] == s4[0]){
		ans.push_back('1');
		//cout << "在同一节排" << endl; 
	}else{
		ans.push_back('0');
		//cout << "不在同一排" << endl;
	}
	if(s1 == s3 && s2[1] == s4[1] && s2[0] == s4[0]){
		if((s2[2] >= 'A' && s2[2] <= 'C') && (s4[2] >= 'A' && s4[2] <= 'C')){
			ans.push_back('1');
			//cout << "在同一侧" << endl; 
		}else if((s2[2] >= 'D' && s2[2] <= 'F') && (s4[2] >= 'D' && s4[2] <= 'F')){
			ans.push_back('1');
			//cout << "在同一侧" << endl; 
		}else{
			ans.push_back('0');
			//cout << "不在同一侧" << endl; 
		}
	}else{
		ans.push_back('0');
		//cout << "不在同一侧" << endl; 
	} 
	if(s1 == s3 && s2[1] == s4[1] && s2[0] == s4[0]){
		if((s2[2] >= 'A' && s2[2] <= 'C') && (s4[2] >= 'A' && s4[2] <= 'C')){
			if(s2[2] - s4[2] == 1 || s4[2] - s2[2] == 1){
				ans.push_back('1');
				//cout << "相邻" << endl;
			}else{
				ans.push_back('0');
				//cout << "不相邻" << endl;
			}
		}else if((s2[2] >= 'D' && s2[2] <= 'F') && (s4[2] >= 'D' && s4[2] <= 'F')){
			if(s2[2] - s4[2] == 1 || s4[2] - s2[2] == 1){
				ans.push_back('1');
				//cout << "相邻" << endl;
			}else{
				ans.push_back('0');
				//cout << "不相邻" << endl;
			}
		}else{
			ans.push_back('0');
			//cout << "不相邻" << endl;
		}
	}else{
		ans.push_back('0');
		//cout << "不相邻" << endl;
	}
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
	}
	return 0;
} 
