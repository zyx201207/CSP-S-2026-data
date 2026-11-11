#include <bits/stdc++.h>			
using namespace std;

double c1 ,c2[4] ,c3 , c4[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin >> c1 ;
	for(int i = 1 ; i <= 3 ; i++){
		cin >> c2[i];
	}
	cin >> c3 ;
	for(int i = 1 ; i <= 3 ; i++){
		cin >> c4[i];
	}
	if(c1 == c3){
		cout << "1";
	}	
	else{
		cout << "0";
	}
	if(c2[1] == c4[1]&&c2[2] == c4[2]){
		cout << "1" ;
	}
	else{
		cout << "0";
	}
	if(c2[3] == 'A'){
		if(c2[4] == 'B'){
			cout << "1";
		}
		else if(c4[3] == 'c'){
			cout << "1";
		}
	}
	else if(c2[3] == 'B'){
		if(c2[4] == 'A'){
			cout << "1";
		}
		else if(c4[3] == 'C'){
			cout << "1";
		}
	}
	else if(c2[3] == 'C'){
		if(c2[4] == 'A'){
			cout << "1";
		}
		else if(c4[3] == 'B'){
			cout << "1";
		}
	}
	else if(c2[3] == 'D'){
		if(c2[4] == 'F'){
			cout << "1";
		}
	}
	else if(c2[3] == 'F'){
	 	if(c2[4] == 'D'){
			cout << "1";
		}	
	}
	else{
		cout <<"0";
	}
	if(c2[3] == 'A'){
		if(c4[3] == 'B'){
			cout << "1";
		}
	}
	else if(c2[3] == 'B'){
		if(c4[3] == 'A'){
			cout << "1";
		}
		else if(c4[3] == 'C'){
			cout << "1";
		}
	}
	else if(c2[3] == 'C'){
		if(c4[3] == 'B'){
			cout << "1";
		}
	}
	else if(c2[3] == 'D'){
		if(c4[3] == 'F'){
			cout << "1";
		}
	}
	else if(c2[3] == 'F'){
		if(c4[3] == 'D'){
			cout << "1";
		}
	}
	else{
		cout << "0";
	}
	return 0;
}
