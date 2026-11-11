#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
int fun(char c){
	if(c=='A'||c=='B'||c=='C'){
		return 0;
	}
	else{
		return 1;
	}
}
bool g(char c,char d){
	if(fun(c)==0){
		if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')){
			return true;	
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(fun(s1[2])==fun(s2[2])){
				cout<<"1";
				if(g(s1[2],s2[2])){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
