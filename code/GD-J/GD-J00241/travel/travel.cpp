#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	int s1ph = s1[2]-'A';
	int s2ph = s2[2]-'A';
	
	bool b1 = c1==c2;
	bool b2 = (""+s1[0]+s1[1])==(""+s2[0]+s2[1]);
	bool b3 = ((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));
	bool b4 = min(s1ph,s2ph)+1==max(s1ph,s2ph);
	
	if(b1){
		cout << 1; 
	}else{
		cout << 0;
	}
	if(b1&&b2){
		cout << 1; 
	}else{
		cout << 0;
	}
	if(b1&&b2&&b3){
		cout << 1; 
	}else{
		cout << 0;
	}
	
	
	if(b1&&b2&&b3&&b4){
		cout << 1; 
	}else{
		cout << 0;
	}
} 
