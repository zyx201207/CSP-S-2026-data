#include<iostream>
#include<string>
using namespace std;
bool f[4]={1,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){cout<<"0000";return 0;}
	int a1=(s1[0]-'0')*10+s1[1]-'0',a2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1!=a2){cout<<"1000";return 0;}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){cout<<"1111";return 0;}
		else{cout<<"1110";return 0;}
	}else{cout<<"1100";return 0;}
	return 0;
}  
