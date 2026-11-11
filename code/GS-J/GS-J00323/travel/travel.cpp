#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c{-1} , c2{-1};
	string z = "-1" , z2 = "-1";
	cin >> c >> z >> c2 >> z2;
	string sub_z = z.substr(0,2);//ÅÅÊı 
	string sub_z2 = z2.substr(0,2);//ÅÅÊı 
	string substr_uni_z = z.substr(2,1);//×ÖÄ¸»º´æ 
	string substr_uni_z2 = z2.substr(2,1);//×ÖÄ¸»º´æ 
	char _2_z = substr_uni_z[0];
	char _2_z2 = substr_uni_z2[0];
	
	if(c==c2){
		cout << 1 ;
		
		if(sub_z == sub_z2){
			cout << 1 ;
			
			if((_2_z >= 'A'&&_2_z<='C'&&_2_z2 >= 'A'&&_2_z2<='C')||((_2_z=='F'||_2_z=='D')&&(_2_z2=='F'||_2_z2=='D'))){
				cout << 1 ;
				
				if(int(_2_z)+1==int(_2_z2)||int(_2_z)-1==int(_2_z2)){
					
					cout << 1 ;
				}else{
					
					cout << '0' ;
					return 0;
				}
			}else{
				cout << "00" ;
				return 0;
			}
		}else{
			cout << "000" ;
			return 0;
		}
	}else{
		cout << "0000" ;
		return 0;
	}
	
}
