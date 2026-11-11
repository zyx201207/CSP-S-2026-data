#include <bist/c++.h>
using namespace std;
int main(){
    int c1, c3;
    cin >> c1 >> c3;
    string c2, c4;
    cin >> c2 >> c4;

    if(c1==c3){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(c2-c3==1){
		cout << "1";
	}
	else{
		cout << "0";
	}


    return 0;
}
