#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a=false,b=false,c=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2){
		cout<<1;
		c=true;
	}
	else{
		cout<<0;
	}
	if (s1[0]==s2[0]&&s1[1]==s2[1]&&c){
		cout<<1;
		b=true;
	}
	else{
		cout<<0;
	}
	if (((s1[2]-'A'<3&&s2[2]-'A'<3)||(s1[2]-'A'>2&&s2[2]-'A'>2))&&b){
		cout<<1;
		a=true;
	}
	else{
		cout<<0;
	}
	if (abs(s1[2]-s2[2])==1&&a){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
