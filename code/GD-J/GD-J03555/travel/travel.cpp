#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans1,ans2,ans3,ans4;
bool pangduan(string a,string b){
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A'&&s2[2]=='B'){
			return 1;
		}
		if(s1[2]=='A'&&s2[2]=='C'){
			return 1;
		}
		if(s1[2]=='B'&&s2[2]=='C'){
			return 1;
		}
		if(s1[2]=='B'&&s2[2]=='A'){
			return 1;
		}
		if(s1[2]=='C'&&s2[2]=='A'){
			return 1;
		}
		if(s1[2]=='C'&&s2[2]=='B'){
			return 1;
		}
		if(s1[2]=='D'&&s2[2]=='F'){
			return 1;
		}
		if(s1[2]=='F'&&s2[2]=='D'){
			return 1;
		}
	}
	else return 0;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans1="1";
	}
	else ans1 = "0";
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&ans1=="1"){
		ans2="1";
	}
	else ans2= "0";
	if(pangduan(s1,s2)&&ans2=="1"){
		ans3="1";
	}
	else ans3= "0";
	if(ans3=="0"){
		ans4 = "0";
	}
	else{
		if(s1[2]=='B'||s2[2]=='B'||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
			ans4="1";
		}
		else ans4 = "0";
	}
	string anszong = ans1+ans2+ans3+ans4;
	cout<<anszong;
	return 0;
} 
