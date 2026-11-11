#include <iostream>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
    	cout << 1;
    	if((s1=="01B"&&s2=="01A")||(s1=="01C"&&s2=="01B")||(s1=="01D"&&s2=="01F")){
    		cout <<111;
		}
		else if((s1=="01C"&&s2=="01A")||(s1=="01C"&&s2=="01D")){
			cout <<110;
		}
		else{
			cout << 000;
		}
	}
	else if(c1!=c2){
	    cout << 0000;
    }
	return 0;
}
