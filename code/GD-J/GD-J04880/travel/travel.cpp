#include<iostream>
#include<cstdio>
using namespace std;
string s[4];
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++) cin>>s[i];
	if(s[0]==s[2]) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if((s[1][2]-'A'<3&&s[3][2]-'A'<3)||(s[1][2]-'A'>=3&&s[3][2]-'A'>=3)) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	x=s[1][2]-'A',y=s[3][2]-'A';
	if(x<y) swap(x,y);
	if(x-y==1&&x!=3&&y!=2) cout<<1;
	else cout<<'0';
	return 0;
}
