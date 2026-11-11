#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);  
	freopen("travel.out","w",stdout);cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	if (s1[0]==s2[0]&&s1[1]==s2[1]) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	char t1 = s1[2], t2 = s2[2];
	if ((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))cout << 1;
	else{
		cout << "00";
		return 0;
	}
	if(abs(int(t1-t2))==1||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))cout << 1;
	else cout <<"0";
}
