//贵州师范大学贵安新区附属初级中学 刘炫希 GZ-J00121
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;


	string ns1=s1.substr(0,2);
	string ns2=s2.substr(0,2);

	char ws1=s1[2];
	char ws2=s2[2];
	int ok1=0,ok2=0,ok3=0,ok4=0;
	if (c1==c2){
		ok1=1;
		if (ns1==ns2){
			ok2=1;
			if ((ws1<='C' && ws2<='C') || (ws1>='D' && ws1<='F') && (ws2>='D' && ws2<='F')){
				ok3=1;
				if (abs(ws1-ws2)==1){
					ok4=1;
				}
			}
		}
	}else{
		cout <<"0000";
		return 0;
	}

	if (ok1){
		cout <<1;
	}else{
		cout <<0;
	}
	if (ok2){
		cout <<1;
	}else{
		cout <<0;
	}
	if (ok3){
		cout <<1;
	}else{
		cout <<0;
	}
	if (ok4){
		cout <<1;
	}else{
		cout <<0;
	}
	return 0;
}

