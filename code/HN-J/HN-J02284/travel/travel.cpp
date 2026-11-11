#include "bits/stdc++.h"
using namespace std;
string s_1 ,s_2 ,c_1 ,c_2 ,p1a ,p1b ,p2a ,p2b ,ce1 ,ce2;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	p1a = s_1[0] , p1b = s_1[1];
	p2a = s_2[0] , p2b = s_2[1];
	//cout<<p1a<<" "<<p1b<<" "<<p2a<<" "<<p2b;
	if(c_1 == c_2){
		cout << 1;
		if(p1a == p2a && p1b == p2b){
			cout << 1;
			ce1 = s_1[2] ,ce2 = s_2[2];
			if(ce1 == "A" || ce1 == "B" || ce1 == "C"){
				if(ce2 == "A" || ce2 == "B" || ce2 == "C"){
					
					cout<<1;
					if((ce1 == "A" && ce2 == "C")||(ce1 == "C" && ce2 == "A")){
						cout<<0;
					}else{
						cout<<1;
					}
				}else{
					cout<<0<<0;
				}
			}else{
				if(ce2 == "D" || ce2 == "E"){
					cout<<1<<1;
				}else{
					cout<<0<<0;
				}
			}	
		}else {
			cout<<0<<0<<0;
		}
	}else {
		cout<<0<<0<<0<<0;
	}
	return 0;
}
