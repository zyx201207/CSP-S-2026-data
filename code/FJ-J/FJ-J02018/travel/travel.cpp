#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	string Rone,Rtwo,Xone,Xtwo;
	bool RX = 1;
	cin >> Rone >> Rtwo >> Xone >> Xtwo;
	
	//车厢 
	if(Rone == Xone) cout << "1";
	else{
		cout << "0";
		RX = 0;
	}
	
	//将行数和座位分开 
	char Rnum,Rseat;
	for(int i=0;i<=1;i++){
		Rnum += Rtwo[i];
	}
	Rseat = Rtwo[2];
	
	char Xnum,Xseat;
	for(int i=0;i<=1;i++){
		Xnum += Xtwo[i];
	}
	Xseat = Xtwo[2];
	
	//判断行数 
	if((Rnum == Xnum) && RX) cout << "1";
	else{
		cout << "0";
		RX = 0;
	}
	
	//相邻条件 
	int a = 0;
	if(Rseat < Xseat){
		a = Xseat - Rseat;
	}
	
	else{
		a = Xseat - Rseat;
	}
	
	//是否同侧
	if((Rseat >= 'A' && Rseat <= 'C') && (Xseat >= 'A' && Xseat <= 'C') && RX) cout << "1";
	else if((Rseat == 'D' && Xseat == 'F') || (Rseat == 'F' && Xseat == 'D') && RX) cout << "1";
	else{
		cout << "0";
		RX = 0;
	}
	
	//是否相邻
	if((a == 1) && RX) cout << "1";
	else cout << "0";
	
	return 0;
}
