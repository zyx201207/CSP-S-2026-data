#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
bool a[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int c_1=(c1[0]-'0')*10+(c1[1]-'0'),c_2=(c2[0]-'0')*10+(c2[1]-'0');
	int s_1=(s1[0]-'0')*10+(s1[1]-'0'),s_2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c_1==c_2){
		cout<<'1';
	}
	else {
		cout<<'0';
		a[1]=1;
	}
	if(!a[1] && s_1==s_2){
		cout<<'1';
	}
	else{
		cout<<'0';
		a[2]=1;
	}
	if(!a[2] && (('D'<=s1[2] && 'F'>=s1[2] && 'D'<=s2[2] && 'F'>=s2[2]) || ('A'<=s1[2] && 'C'>=s1[2] && 'A'<=s2[2] && 'C'>=s2[2]))){
		cout<<'1';
	}
	else{
		cout<<'0';
		a[3]=1;
	}
	if(!a[3] && abs(s1[2]-s2[2])==1){
		if((s1[2]=='D' && s2[2]=='C') || (s2[2]=='D' && s1[2]=='C')) cout<<'0';
		else cout<<'1';
	}
	else cout<<'0';
	return 0;
}
