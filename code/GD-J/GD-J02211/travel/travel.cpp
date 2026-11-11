#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//分别表示小 R 的车票上的车厢号、座位号，以及小 X 的车票上的车厢号、座位号
	int a,c;
	string b,d;
	cin >> a >> b >> c >> d;
	int numb = 0,numd = 0;
	char chb,chd;
	for(int i = 0;i <= 2;i++){
		if((b[i] >= '0' && b[i] <= '9') && (d[i] >= '0' && d[i] <= '9')){
			numb = numb * 10 + (b[i] - '0');
			numd = numd * 10 + (d[i] - '0');
		}
		if(!(b[i] >= '0' && b[i] <= '9')){
			chb = b[i];
		}
		if(!(d[i] >= '0' && d[i] <= '9')){
			chd = d[i];
		}
	}
	if(a == c){
		cout << "1"; 
	}
	if(a != c){
		cout << "0000";
		return 0;
	}
	if(numb == numd){
		cout << "1";
	}
	if(numb != numd){
		cout << "000";
		return 0;
	}
	if((chb == 'A' && chd == 'B') || (chb == 'A' && chd == 'C') || (chb == 'B' && chd == 'C') || (chb == 'D' && chd == 'F') || (chd == 'A' && chb == 'B') || (chd == 'A' && chb == 'C') || (chd == 'B' && chb == 'C') || (chd == 'D' && chb == 'F')){
		cout << "1";
	}
	if(!((chb == 'A' && chd == 'B') || (chb == 'A' && chd == 'C') || (chb == 'B' && chd == 'C') || (chb == 'D' && chd == 'F') || (chd == 'A' && chb == 'B') || (chd == 'A' && chb == 'C') || (chd == 'B' && chb == 'C') || (chd == 'D' && chb == 'F'))){
		cout << "00";
		return 0;
	}
	if((chb == 'A' && chd == 'B') || (chb == 'B' && chd == 'C') || (chb == 'D' && chd == 'F') || (chd == 'A' && chb == 'B') || (chd == 'B' && chb == 'C') || (chd == 'D' && chb == 'F')){
		cout << "1";
	}
	if(!((chb == 'A' && chd == 'B') || (chb == 'B' && chd == 'C') || (chb == 'D' && chd == 'F') || (chd == 'A' && chb == 'B') || (chd == 'B' && chb == 'C') || (chd == 'D' && chb == 'F'))){
		cout << "0";
	}
	return 0;
} 

