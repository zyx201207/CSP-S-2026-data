#include<iostream>
using namespace std;
string c[2],s[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin>>c[0]>>s[0]>>c[1]>>s[1];
	if(c[0]==c[1]){
		cout<<'1';
		if(s[0][0]==s[1][0]&&s[0][1]==s[1][1]){
			cout<<'1';
			if((s[0][2]<='C')==(s[1][2]<='C')){
				cout<<'1';
				if(s[0][2]-s[1][2]==1||s[1][2]-s[0][2]==1||s[0][2]>'C')cout<<'1';
				else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
