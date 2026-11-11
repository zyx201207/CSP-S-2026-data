#include <bits/stdc++.h>
using namespace std;

bool sameSide(char R, char X){
	// 是否同一侧
	if (R=='F' || R=='D'){
		// 在上方 
		if (X=='F'||X=='D') return true;
		else return false;
	} else {
		// 在下方 R==C/B/A
		if (X!='F'&& X!='D') {
			return true;
		} else return false;
	}
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string cR, cX; // 即输入中的c1，c2 小R、X的车厢号 
	string sR;
	string sX;
	cin >> cR >> sR >> cX >> sX;
	
	// 是否同一节车厢 
	bool samebox=false;
	if (cR==cX) {
		samebox=true;
		cout << 1;
	} else cout << 0;
	
	// 是否同一排 且同一节车厢 
	bool samepai = false;
	if (samebox){
		if (sR[0]==sX[0] && sR[1]==sX[1]){
			samepai = true;
			cout << 1;
		} else cout << 0;
	} else cout << 0;
	
	// 是否位于过道同一侧 且同一排同一节车厢 
	char seatR = sR[2]; // 小R的座位 
	char seatX = sX[2]; // 小X的座位 
	
	bool sameside = false;
	if (samebox && samepai && sameSide(seatR, seatX)){
		sameside = true;
		cout << 1;
	} else cout << 0;
	
	// 是否相邻 (前提是同一侧） 
	if (sameside && abs(seatR-seatX)==1) cout << 1;
	else cout << 0;
	
	return 0; 
	 
	
}
