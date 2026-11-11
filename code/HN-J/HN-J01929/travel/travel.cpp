#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}else{
		cout <<"1" ;
		if(s1.substr(0,2) != s2.substr(0,2)){
			cout <<"000";
			return 0;
		}else{
			cout <<"1";
			bool f1 = s1[2] > 'C';
			bool f2 = s2[2] > 'C';
			if(f1 != f2){
				cout << "00";
			}else{
				cout << "1";
				if(abs(int(s1[2] - s2[2] )) == 1 ){
					cout <<1;
				}else{
					cout <<0;
				}
			}
		}
	}
	return  0;
} 
