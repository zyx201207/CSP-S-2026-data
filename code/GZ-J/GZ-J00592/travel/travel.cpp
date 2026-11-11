//GZ-J00592
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;

int main(){	
	freopen("travel4.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	//同车厢
	int a1 = (c1[0] - '0') * 10 + (c1[1] - '0');
	int a2 = (c2[0] - '0') * 10 + (c2[1] - '0');
	if(a1 == a2){
		cout << "1";		
	}else{
		cout << "0000";
		return 0;
	}
	
	//同排
	int b1 = (s1[0] - '0') * 10 + (s1[1] - '0');
	int b2 = (s2[0] - '0') * 10 + (s2[1] - '0');
	if (b1 == b2){
		cout << "1"; 
	}else{
		cout << "000";
		return 0;
	}
	
	//同侧
	if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') ||
		(s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F') ){
			cout << "1";
		}else{
			cout << "00";
			return 0; 
		}
	
	//相邻
	if (abs((s1[2] - '0') - (s2[2] - '0')) == 1){
		cout << "1";
	}else {
		cout << "0";
	} 
	
	return 0;
}

