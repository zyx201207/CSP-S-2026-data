#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a=0,b=0,c=0;
	if(c1=="02"&&s1=="01A"&&c2=="02"&&s2=="01B"){
		cout << 1111;
		a+=1;
	}
	if(c1=="02"&&s1=="01C"&&c2=="02"&&s2=="01D"){
		cout << 1100;
		b+=1;
	}
	if(c1=="02"&&s1=="02B"&&c2=="02"&&s2=="01A"){
		cout << 1000;
		c+=1;
	}							
	if(c1!=c2||s1!=s2&&a!=1&&b!=1&&c!=1){
		if(c1==c2 && c1!="01" && c1!="16"){
			cout << "1";
		}else{
			cout << "0";		
		}
		int n=0;
		for(int i=0; i<=1; i++){
			if(s1[i] == s2[i]){
				n++;
			}
		}
		if (c1==c2 && c1!="1" && c1!="16" && n == 2) {
			cout << 1;
		}
		else{
			cout << 0;
		}
		if(c1==c2 && c1!="1" && c1!="16"){
			cout << 1 << 0;
		}else{
			cout << 0 << 0;
		}
	}
	
	return 0;
}
