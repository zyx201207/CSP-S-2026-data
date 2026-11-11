#include<bits/stdc++.h>
using namespace std;
string c[3],s[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]!=c[2]){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	}
	if(s[1][0]!=s[2][0]||s[1][1]!=s[2][1]){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}
	if(s[1][2]>='D'&&s[2][2]>='D')cout<<"1";
	else if(s[1][2]<'D'&&s[2][2]<'D')cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	if(s[1][2]-s[2][2]==-1||s[1][2]-s[2][2]==1)cout<<"1";
	else cout<<"0";
	return 0;
}
