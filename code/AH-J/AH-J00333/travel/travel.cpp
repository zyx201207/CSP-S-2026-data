#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,s1,t;
	char c2,s2;
	cin>>t;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"11";
		}
	else{
		cout<<"00";
		}
	if(c2==char(t)&&s2==char(t+1)){
		cout<<"11";
		}
	if(c2==char(t)&&s2==char(t+2)||c2==char(t)&&s2==char(t+3)||c1==char(t)&&s1==char(t+4)){
		cout<<"0";	
		}
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w","stdout");
	return 0;
}
