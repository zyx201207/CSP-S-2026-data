#include <bits/stdc++.h>
using namespace std;
string check(char a,char b){
	string res="";
	if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
		res+="1";
		if(a==b+1||b==a+1) res+="1";
		else res+="0";
	}
	if(a>='D'&&a<='F'&&b>='D'&&b<='F'){
		res+="1";
		if(a=='D'&&b=='F') res+="1";
		else res+="0";
	}
	if(res=="") return "00";
	else return res;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			cout<<check(s1[2],s2[2]);
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
