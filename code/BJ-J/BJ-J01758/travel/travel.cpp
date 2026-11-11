#include <iostream>

using namespace std;

int main(){
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	int a1 ,a2 ,b1 ,b2;
	char c1 ,c2;
	cin >> a1 >> b1 >> c1;
	cin >> a2 >> b2 >> c2;
	if(a1!=a2){
        cout << "0000" << endl;
        return 0;
	}
	if(b1!=b2){
        cout << "1000" << endl;
        return 0;
	}
	if(c1-'A'<=2 && c2-'A' <=2){
        if(c1-c2==1 || c2-c1==1){
            cout << "1111" << endl;
            return 0;
        }
        cout << "1110" << endl;
        return 0;
	}
	if(c1-'A'>=3 && c2-'A'>=3){
        cout << "1111" << endl;
        return 0;
	}
	cout << "1100" << endl;
	return 0;
}
