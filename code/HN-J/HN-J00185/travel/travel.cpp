#include<bits/stdc++.h>
using namespace std;
string s_1,s_2,se_1,se_2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s_1>>se_1>>s_2>>se_2;
	if(s_1==s_2)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(se_1[0]==se_2[0]&&se_1[1]==se_2[1]){
		cout<<"1";
		if(se_1[2]>='A'&&se_1[2]<='C'&&se_2[2]>='A'&&se_2[2]<='C'){
			cout<<"1";
			if(abs(se_1[2]-se_2[2])==1)cout<<"1";
			else cout<<"0";
		}
		else if(se_1[2]>='D'&&se_1[2]<='E'&&se_2[2]>='D'&&se_2[2]<='E')cout<<"11";
		else cout<<"00";
	}
	else cout<<"000";
}
