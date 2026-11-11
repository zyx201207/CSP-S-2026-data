#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int c,s;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==s1){
		cout<<"1";
		if(c1[0]==s1[0]&&c1[1]==s1[1]){
			cout<<"1";
			if((c2[2]<='C'&&s2[2]<='C')||('D'<=c2[2]&&'D'<=s2[2])){
				cout<<"1";
				if(c2[2]-s2[2]==1||s2[2]-c2[2]==1) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
