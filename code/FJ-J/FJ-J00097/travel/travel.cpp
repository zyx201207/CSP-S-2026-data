#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
string c[5],s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]){
		cout<<'1';
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]){
			cout<<'1';
			if((s[1][2]<'D'&&s[2][2]<'D')||(s[1][2]>'D'&&s[2][2]>'D')){
				cout<<'1';
				if(abs(s[1][2]-s[2][2])==1) cout<<'1';
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
