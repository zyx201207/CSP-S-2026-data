#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,a11=0,b11=0;
	string a1,b1,a2,b2;
	cin >> a >> a1 >> b >> b1;
	
	if(a == b){
		cout << "1";
	}else{
		cout << "0";
	}
	
	for(int i = 0;i < 2;i++){
		if(int(a1[i])-48 != 0){
		    a11*=10;
		    a11 += int(a1[i])-48;
	    }
	}
	for(int i = 0;i < 2;i++){
		if(int(b1[i])-48 != 0){
			b11*=10;
			b11 += int(b1[i])-48;
		}
		
	}

	if(a11 == b11 && a == b){
		cout << "1";
	}else{
		cout << "0";
	}
	a2=a1[2];
	b2=b1[2];
	if((a2 == "F" && b2  == "D" || b2 == "F" && a2  == "D") && a11==b11){
	    cout << "11";
	    return 0;
	}else if((a2 == "A" && b2  == "B" || b2 == "A" && a2  == "B" || a2 == "B" && b2  == "C" || b2 == "B" && a2  == "C") && a11==b11){
	    cout << "11";
	    return 0;
	}else if((a2 == "A" && b2  == "C" || b2 == "A" && a2  == "C") && a11==b11){
	    cout << "10";
	    return 0;
	}else{
		cout << "00";
	}
	
	return 0;
}
