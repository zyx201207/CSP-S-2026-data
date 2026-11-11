#include<iostream>
#include<string>
using namespace std;
string c1,c2,c3,c4;
bool f(char a){
	if(a=='A'||a=='B'||a=='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<"1";
			if(f(c2[2])==f(c4[2])){
				cout<<"1";
				if(f(c2[2])){
					if(c2[2]==c4[2]+1||c2[2]==c4[2]-1){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else{
					cout<<"1";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
