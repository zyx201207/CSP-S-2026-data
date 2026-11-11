#include<bits/stdc++.h>
using namespace std;

int x[5];
string R1[2], R2[3], X1[2], X2[3];

int main(){
	int A, B, C = 1;
	int D, F = 0;
	cin >> R1[1,2] >> R2[1,2,3] >> X1[1,2] >> X2[1,2,3];
	
	if(R1 == X1){
		x[1] = 1;
	}
	else{
		x[1] = 0;
	}
	
	if(R2[1] == X2[1] & R2[2] == X2[2]){
		x[2] = 1;
	}
	else{
		x[2] = 0;
	}
	
	if(x[2] == 1 & R2[3] == X2[3]){
		x[3] = 1;
	}
	else{
		x[3] = 0;
	}
	
	if(R[3] + "&" + X[3] == "A&B"||"B&C"||"D&F"){
		x[4] = 1;
	}
	else{
		x[4] = 0;
	}
	
	else if(R1 != R2){
		cout << "0000" << endl;
	}
	
	for(int i = 1; i < 4; i++)
	{
		cout << x[i];
	}
	
	return 0;
}
