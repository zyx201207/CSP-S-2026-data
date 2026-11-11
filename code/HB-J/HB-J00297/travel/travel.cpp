#include<bits/stdc++.h>
using namespace std;

string s1,s2,s3;
int main(){
	//freopen("treavl.in","r",std);
	//freopen("treavl.out","w",std);
	cin >> c1 >> s1 >> c2>> s2;
	if(c1==c2){
		cout << "E";
		if(s1[0]=s2[0] && s1[1]=s2[1]) {
			cout << "F";
		} else {
			cout << "1000";
		} else {
			cout << "0000";
		}
	}
	return 0; 
}
