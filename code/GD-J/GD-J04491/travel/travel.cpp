#include <iostream>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	char cR[3], sR[4], cX[3], sX[4];
	int cSame = 1, pSame = 1, gSame = 1, xSame = 1;
	cin>>cR>>sR>>cX>>sX;
	
	for(int i = 0; i < 2; i++){
		if(cR[i] != cX[i]){
			cSame = 0;
		}
	}
	if(cSame == 0){
		cout<<"0000";
		return 0;
	}
	
	for(int i = 0; i < 2; i++){
		if(sR[i] != sX[i]){
			pSame = 0;
		}
	}
	if(pSame == 0){
		cout<<"1000";
		return 0;
	}
	
	if((sR[2] <= 'C' && sX[2] > 'C') || (sR[2] > 'C' && sX[2] <= 'C')){
		cout<<"1100";
		return 0;
	}
	
	if(sR[2] <= 'C'){
		if(sR[2] != 'B' && sX[2] != 'B'){
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	
	return 0;
} 
