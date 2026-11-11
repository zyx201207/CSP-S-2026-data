#include<bits/stdc++.h>//Trick||Treat!
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){//同车厢 
		cout << 1;
		char a1,b1,c1,a2,b2,c2;
		a1=s1[0];
		b1=s1[1];
		c1=s1[2];
		a2=s2[0];
		b2=s2[1];
		c2=s2[2];
		if(a1==a2&&b1==b2){//同排 
			cout << 1;
			if(  ((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')) ||  ((c1=='D'||c1=='F')&&(c2=='D'||c2=='F'))  ){//同边 
				cout << 1;
				if(abs(c1-c2)==1){
					cout << 1;
					return 0;
				}else{
					cout << 0;
					return 0;
				}
			}else{
				cout << "00";
				return 0;
			}
		}else{
			cout << "000";
			return 0; 
		}
	}else{
		cout << "0000";
		return 0;
	}
	
	
	
	
	
	return 0;
} 
