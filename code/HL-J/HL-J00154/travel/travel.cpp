#include<bits/stdc++.h>
using namespace std;
int c1,c3;
string c2,c4;
int main(){
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		cout << "1";
	}else{
		cout << 0;
	}
	
	if(c2[0] == c4[0] && c2[1] == c4[1]){
		cout << "1";
	}else{
		cout << "0";
	}
	
	if(c2[2] == 'A' && c4[2] == 'B'){
		cout << "1";
    }
	else if(c2[2] == 'B' && c4[2] == 'A'){
		cout << "1";
	}else if(c2[2] == 'A' && c4[2] == 'C'){
		cout << "1"; 
	}else if(c2[2] == 'C' && c4[2] == 'A'){
		cout << "1";
    }else if(c2[2] == 'B' && c4[2] == 'C'){
		cout << "1";
    }else if(c2[2] == 'C' && c4[2] == 'B'){
		cout << "1";
    }else if(c2[2] == 'D' && c4[2] == 'E'){
		cout << "1";
    }else if(c2[2] == 'E' && c4[2] == 'D'){
		cout << "1";
    }else{
    	cout << "0";
	}
	
	if(c2[2] == 'A' && c4[2] == 'B'){
		cout << "1";
	}
	else if(c2[2] == 'B' && c4[2] == 'A'){
		cout << "1";
	}else if(c2[2] == 'B' && c4[2] == 'C'){
		cout << "1";
    }
	else if(c2[2] == 'C' && c4[2] == 'B'){
		cout << "1";
	}else if(c2[2] == 'D' && c4[2] == 'E'){
		cout << "1";
	}
	else if(c2[2] == 'E' && c4[2] == 'D'){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
} 

