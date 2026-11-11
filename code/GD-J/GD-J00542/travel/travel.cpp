#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a, aaa, b, bbb;
    cin >> a >> aaa >> b >> bbb;
    if(a == b){
        cout << "1";
    }
    else{
        cout << "0000";
        return 0;
    }
    int _a = (aaa[0] - '0') * 10 + aaa[1] - '0',_b = (bbb[0] - '0') * 10 + bbb[1] - '0';
    if(_a == _b){
        cout << "1";
    }
    else{
        cout << "000";
        return 0;
    }
    if(aaa[2] == 'A'||aaa[2] == 'B'||aaa[2] == 'C'){
        if(bbb[2] == 'A'||bbb[2] == 'B'||bbb[2] == 'C'){
            cout << "1";
        }
        else{
            cout << "00";
            return 0;
        }
    }
    else{
        if(bbb[2] == 'D'||bbb[2] == 'E'){
            cout << "11";
            return 0;
        }
        else{
            cout << "00";
            return 0;
        }
    }
    if((aaa[2] == 'A' && bbb[2] == 'B')||(aaa[2] == 'B' && bbb[2] == 'A')) {
    	cout << "1";
    	return 0;
	}
	else if((aaa[2] == 'B' && bbb[2] == 'C')||(aaa[2] == 'C' && bbb[2] == 'B')){
		cout << "1";
		return 0;
	}
	else{
		cout << "0";
	}
	return 0;
}
