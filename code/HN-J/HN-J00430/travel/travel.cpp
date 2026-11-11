#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1 == c2) cout << "1";
	else{
		cout << "0000";
		return 0;
	}
	
	string x1, x2;//单独提取出行数
	x1 += s1[0]; x1 += s1[1];
	x2 += s2[0]; x2 += s2[1];
	if(x1 == x2) cout << "1";
	else{
		cout << "000";
		return 0;
	}//同一排
	
	int l1, l2;//每排的序列数
	l1 = s1[2] - 'A' + 1;
	l2 = s2[2] - 'A' + 1;//将A,B,C,D,F分别转化为数字1，2，3，4，6；
	bool side1, side2;//0代表在A~C之间， 1代表在D~F之间；
	if(l1<=3 && l1>=1) side1=0; else if(l1==4 || l1==6)side1=1; 
	if(l2<=3 && l2>=1) side2=0; else if(l2==4 || l2==6)side2=1;
	if(side1 == side2) cout << "1";
	else{
		cout << "00";
		return 0;
	};//同一侧
	
	if(side1 == side2 && side1==0){
		if(abs(l1-l2) == 1) cout << "1";
	}else if(side1 == side2 && side1==1){
		cout << "1";
	}else cout << "0";
	
	return 0;
}
