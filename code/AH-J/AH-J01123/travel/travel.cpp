#include<bits/stdc++.h>
using namespace std;
int c_1,c_2;
string s_1,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1!=c_2) cout<<"0000";
	else{
		cout<<"1";
		if(s_1[0]!=s_2[0]||s_1[1]!=s_2[1]) cout<<"000";
		else{
			cout<<"1";
			if((s_1[2]<='C'&&s_2[2]>'C')||(s_2[2]<='C'&&s_1[2]>'C')) cout<<"00";
			else{
				cout<<"1";
				if(abs(s_1[2]-s_2[2])==1) cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}
