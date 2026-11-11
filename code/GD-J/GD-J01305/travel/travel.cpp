#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>s>>c2>>s2;
	if(c!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s[1]!=s2[1]||s[0]!=s2[0]){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if(s[2]>='D'&&s2[2]<'D'||s[2]<'D'&&s2[2]>='D'){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(int(s[2])-int(s2[2])==1||int(s2[2])-int(s[2])==1||s[2]=='D'&&s2[2]=='F'||s[2]=='F'&&s2[2]=='D') cout<<"1";
	else cout<<"0";
	return 0;
} 
