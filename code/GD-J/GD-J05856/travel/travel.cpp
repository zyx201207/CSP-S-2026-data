#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	string c5,c6;
	c5+=c2[0];
	c5+=c2[1];
	c6+=c4[0];
	c6+=c4[1];
	//cout<<endl<<c5<<" "<<c6;
	if(c5!=c6){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if((c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C'))||(c2[2]=='B'&&(c4[2]=='A'|c4[2]=='C'))||(c2[2]=='C'&&(c4[2]=='B'||c4[2]=='A'))||(c2[2]=='F'&&c4[2]=='D')||(c2[2]=='D'&&c4[2]=='F')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((c2[2]=='A'&&(c4[2]=='B'))||(c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C'))||(c2[2]=='C'&&(c4[2]=='B'))||(c2[2]=='D'&&(c4[2]=='F'))||(c2[2]=='F'&&(c4[2]=='D'))){
		cout<<"1";
	}
	else cout<<"0";
}
