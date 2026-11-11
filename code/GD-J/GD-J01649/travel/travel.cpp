#include<iostream>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			if(c2[2]-64<=3&&c4[2]-64<=3){
				if(abs(c2[2]-c4[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else {
			cout<<"1000";
		}		
	}else cout<<"0000";

		
} 
