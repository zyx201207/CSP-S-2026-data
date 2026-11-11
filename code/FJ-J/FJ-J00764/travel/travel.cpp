#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> t1 >> s2 >> t2;
	if(s1!=s2){
		cout << "0000";
		return 0;
	}
	if(!(t1[0]==t2[0]&&t1[1]==t2[1])){
		cout << "1000";
		return 0;
	}
	if((t1[2]<='C'&&t2[2]>='D')||(t2[2]<='C'&&t1[2]>='D')){
		cout << "1100";
		return 0;
	}
	if((t1[2]=='A'&&t2[2]=='C')||(t1[2]=='C'&&t2[2]=='A')){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}