#include<bits/stdc++.h>
using namespace std; 
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> a2 >> b1 >> b2;
	char s1[3], s2[3];	
	if(a1!=b1){
		cout << 0000;
		return 0;
	}else{	
		if(a2[0]==b2[0]){
			if(a2[1]==b2[1]){
				if(a2[2]>='D' && b2[2]>='D' || a2[2]<='C' && b2[2]<='C'){
					if(a2[2]>='D'){
						cout << 1111;
					}else{
						if(abs(a2[2]-b2[2])==1){
							cout << 1111;
						}else{
							cout << 1110;
						}
					}
				}else{
					cout << 1100;
					return 0;
				}
			}else{
				cout << 1000;
				return 0;
			}
		}else{
			cout << 1000;
			return 0;
		}	
			
	}
	
	return 0;
}
