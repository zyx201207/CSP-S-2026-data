#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	//  车厢号 座位号 车厢号 座位号
	cin >> c1 >> s1 >> c2 >> s2;
	
	string s;
	
	if(c1 == c2){
		s[1] = '1'; 
	}else {          //同一节 
		s[1] = '0';
	}
	
	if(s[1] == '1' && s1[0] == s2[0] && s1[1] == s2[1]){
		s[2] = '1';
	}else {         //同一排 
		s[2] = '0';
	}
	
	char cr = s1[2],cx = s2[2];

	if(s[2] == '1'){
		if((cr >= 'A' && cr <='C') && (cx >= 'A' && cx <='C')){
			s[3] = '1';
		}else if((cr >= 'D' && cr <='F') && (cx >= 'D' && cx <='F')){
			s[3] = '1';           //同一侧 
		}else {
			s[3] = '0';
		}	
	}else {
		s[3] = '0';
	}
	
	if(s[3] == '1'){
		if(cr < cx){
			if(cr + 1 == cx && cr != 'C' && cx != 'D'){
				s[4] = '1';
			}else{
				s[4] = '0';
			}                     //相邻 
		}else if(cr > cx){
			if(cx + 1 == cr && cx != 'C' && cr != 'D'){
				s[4] = '1';
			}else{
				s[4] = '0';
			}
		} else{
			s[4] = '0';
		}
	}else{
		s[4] = '0';
	}
	
	for(int i = 1;i <= 4;i++){
		cout << s[i];
	}

	return 0;
} 
