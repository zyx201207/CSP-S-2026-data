#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
bool q(char a,char b){
if(a=='A'&&b!='B'&&b!='C') return 0;
if(a=='B'&&b!='A'&&b!='C') return 0;
if(a=='C'&&b!='B'&&b!='A') return 0;
if(a=='D'&&b!='F') return 0;
if(a=='F'&&b!='D') return 0;
return 1;
}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
	cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		if(q(s1[2],s2[2])){
			cout<<"1";
			if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
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







fclose(stdin);
fclose(stdout);
}
