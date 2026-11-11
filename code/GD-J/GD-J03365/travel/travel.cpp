#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2){
		cout<<"0000";
		return 0;
	}
	else if(int(s1[0]+s1[1])-'0'-'0'!=int(s2[0]+s2[1])-'0'-'0'){
		cout<<"1000";
		return 0;
	}
	else if((s1[2]>'C'&&s2[2]<='C')||(s1[2]<='C'&&s2[2]>'C')){
		cout<<"1100";
		return 0;
	}
	else if(s1[2]>=++s2[2]||s1[2]<=----s2[2]){
		cout<<"1110";
		return 0;
	}
	else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
