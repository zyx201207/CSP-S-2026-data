#include<bits/stdc++.h>
using namespace std;
string c11,s11,c22,s22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>s11>>c22>>s22;
	if(c11[0]==c22[0]&&c11[1]==c22[1]) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(s11[0]==s22[0]&&s11[1]==s22[1]) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	int a,b;
	if(s11[2]=='A'||s11[2]=='B'||s11[2]=='C') a=1;
	else a=0;
	if(s22[2]=='A'||s22[2]=='B'||s22[2]=='C') b=1;
	else b=0;
	if(a==b) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	char x1=(char)s11[2]+1,x2=(char)s22[2]+1;
	if(x1==s22[2]||x2==s11[2]){
		cout<<1;
	} 
	else cout<<0;
	return 0;
} 
