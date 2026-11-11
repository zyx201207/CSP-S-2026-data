#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	int f = 0;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		for(int i=0;i<3;i++){
			f=0;
			for(int j=0;j<3;i++){
				if(s1[0]==s2[0]){
					if(s1[1]==s2[1]){
						f=1;
						break;	
					}
				}
			}
		}
	}else{
		cout << 0;
	}
				if(f==1){
					cout << 1;
					if(int(s1[2])<=int('C')&&int(s2[2])<=int('C')){
						cout << 1;
						if(int(s1[2]) - 1 == int(s2[2])){
							cout << 1;
						}else if(int(s1[2]) + 1 == int(s2[2])){
							cout << 1;
						}else{
							cout << 0;
						}
					}else if(int(s1[2])>=int('D')&&int(s2[2])>=int('D')){
						cout << 1;
						if(int(s1[2]) + 1 == int(s2[2])){
							cout << 1;
						}if(int(s1[2]) - 1 == int(s2[2])){
							cout << 1;
						}else{
							cout << 0;
						}
					}else{
						cout << 0 <<0;
					}
				}else{
					cout << 0 << 0 << 0;
				}
return 0;
}
