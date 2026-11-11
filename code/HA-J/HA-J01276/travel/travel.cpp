#include<bits/stdc++.h>
using namespace std;
bool panduance(char aa,char bb){
	if(aa<='C' && bb<='C'){
		return 1;
	}
	else if(aa>='D' && bb>='D'){
		return 1;
	}
	else{
		return 0;
	}
}
bool pandua(char a,char b){
	if(a=='A'){
		if(b=='B')return 1;
		else return 0;
	}
	else if(a=='B'){
		if(b=='A' || b=='C')return 1;
		else return 0;
	}
	else if(a=='C'){
		if(b=='B')return 1;
		else return 0;
	}
	else if(a=='D'){
		if(b=='F')return 1;
		else return 0;
	}
	else if(a=='F'){
		if(b=='D')return 1;
		else return 0;
	}
}
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string cc1,ss1,cc2,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	
	string ans="";
	if(cc1==cc2){
		ans+="1";
	}
	else{
		ans+="0";
	}
	
	if(cc1==cc2 && ss1[0]==ss2[0] && ss1[1]==ss2[1]){
		ans+="1";
	}
	else{
		ans+="0";
	}
	
	if(cc1==cc2 && ss1[0]==ss2[0] && ss1[1]==ss2[1] && panduance(ss1[2],ss2[2])){
		ans+="1";
	}
	else{
		ans+="0";
	}
	
	if(cc1==cc2 && ss1[0]==ss2[0] && ss1[1]==ss2[1] && pandua(ss1[2],ss2[2])){
		ans+="1";
	}
	else{
		ans+="0";
	}
	cout<<ans<<'\n';
	return 0;
}
