#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,b1="",d1="",b2="",d2="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	for(int i=0;i<2;i++){
		b1+=b[i];
		d1+=d[i];
	}
	b2=b[2];
	d2=d[2];
	if(a!=c){
		cout << "0000";
		return 0;
	} 
	else{
		if(b1==d1){
			if(b2=="A"&&d2=="B"||b2=="A"&&d2=="C"||b2=="B"&&d2=="A"||b2=="B"&&d2=="C"||b2=="C"&&d2=="A"||b2=="C"&&d2=="B"||b2=="D"&&d2=="F"||b2=="F"&&d2=="D"){
				if(b2=="A"&&d2=="B" || b2=="B"&&d2=="A" || b2=="B"&&d2=="C"||b2=="C"&&d2=="B"||b2=="D"&&d2=="F"||b2=="F"&&d2=="D"){
					cout << "1111";
				}
				else cout << "1110";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}	
} 
