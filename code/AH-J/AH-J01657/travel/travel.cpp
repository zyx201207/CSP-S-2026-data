#include<bits/stdc++.h>
using namespace std;
bool side(char x){
	if(x=='A'||x=='B'||x=='C')return 1;
	return 0;
}
bool ok(char x,char y){
	if((x=='A'&&y=='C')||(x=='C'&&y=='A'))return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(side(s1[2])==side(s2[2])){
				cout<<"1";
				cout<<ok(s1[2],s2[2]);
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
