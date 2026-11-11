#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char x){
	if(x=='A' || x=='B' || x=='C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if(check(s1[2])==check(s2[2])){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)puts("1");
				else puts("0");
			}else puts("00");
		}else puts("000");
	}else puts("0000");
	return 0;
}
