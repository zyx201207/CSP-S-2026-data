#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin >> c1 >> s1 >> c2 >> s2;
	bool a=0,b=0,c=0,d=0;
	if(c1==c2){
		a=1;
	}
	if(a==1){
		bool p=1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				p=0;
				break;
			}
		}
		if(p) b=1;
	}
	if(a==1&&b==1){
		if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
			c=1;
		}	
	}
	if((a==0||b==0||c==0)||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
	}
	else{
		d=1;
	}
	cout << a << b << c << d;
	return 0;
}