#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1s,s2s;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==01||c1==16||c2==01||c2==16){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		cout<<"1";
		s1s=(s1[0]-'0')*10+(s1[1]-'0');
		s2s=(s2[0]-'0')*10+(s2[1]-'0');
		if(s1s==s2s){
			cout<<"1";
			if((s1[2]+1==s2[2]&&s1[2]!='C')||(s1[2]-1==s2[2]&&s1[2]!='C')||(s1[2]=='D'&&s2[2]=='F')){
				cout<<"11";
			}else if((s1[2]+2==s2[2]&&s2[2]!='D')||(s1[2]-2==s2[2]&&s2[2]!='D')){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
