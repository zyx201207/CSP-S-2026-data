#include <iostream>
#include <cstring>
using namespace std; 
string C1,S1,C2,S2;
int main(){
	//freopen("travel.in""r""stdin");
	//freopen("travel.out""w""stdout");
	string C1,S1,C2,S2;
	cin>>C1>>S1>>C2>>S2;
	if(C1==C2){
		cout<<1;}
	else{
		cout<<0;}
	if(C1==C2&&S1[1]==S2[1]&&S1[0]==S2[0]){
		cout<<1;}
	else{
		cout<<0;}
	if(C1==C2&&S1[1]==S2[1]&&S1[0]==S2[0]&&S1[2]<='C'&&S2[2]<='C'){
		cout<<1;}
	else{
		cout<<0;}
	if(C1==C2&&S1[1]==S2[1]&&S1[0]==S2[0]&&S1[2]<='C'&&S2[2]<='C'&&(S1[2]+1||S1[2]-1)==S2[2]){
		cout<<1;}
	else{
		cout<<0;}

return 0;
}