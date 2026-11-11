#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else {
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1) cout<<1;
				else cout<<0;
			}
			else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1) cout<<1;
				else cout<<0;
			}
			else if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')){
				cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1) cout<<1;
				else cout<<0;
			} else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')) cout<<"11";
			else cout<<"00";
		} else cout<<"000";
	}
	return 0;
}
