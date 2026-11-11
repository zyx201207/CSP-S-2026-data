#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string s;
	if(c1==c2){	
	s+='1';
	}
	else  {
		s=s+'0'+'0'+'0'+'0';
    cout<<s;
    return 0;
    }
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		s+='1';
	}
	else {
		s=s+'0'+'0'+'0';
		cout<<s;
		return 0;
	}
	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		s+='1';
		}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'&&s2[2]=='F')){
		s+='1';
	}
	else {
		s=s+'0'+'0';
		cout<<s;
		return 0;
	}
	if((s1[2]==s2[2]+1)||s1[2]==s2[2]-1){
		s+='1';
	}
	else {
		s+='0';
		cout<<s;
		return 0;
	}
	cout<<s;
	return 0;
}
