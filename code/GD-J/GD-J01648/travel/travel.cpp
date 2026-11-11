#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=false,b=false,c=false;
	if(c1==c2){
		b=true;
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(b&&s1[0]==s2[0]&&s1[1]==s2[1]){
		a=true;
		cout<<"1";
	}
	else{
		a=false;
		cout<<"0";
	}
	char x=s1[2],y=s2[2];
	if(a&&b&&(x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')){
		cout<<"1";
		c=true;
	}
	else{
		if(a&&(x=='D'||x=='F')&&(y=='D'||y=='F')){
			cout<<"1";
			c=true;
		}
		else{
			cout<<"0";
		}
	}
	if(a&&b&&c&&(x-y==1||x-y==-1)){
		
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
