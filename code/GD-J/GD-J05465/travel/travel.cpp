#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string a,string b){
	if((a[2]>='A'&&a[2]<='C')&&(b[2]>='A'&&b[2]<='C'))
		return true;
	if((a[2]>='D'&&a[2]<='F')&&(b[2]>='D'&&b[2]<='F'))
		return true;
	return false;
}
bool check2(string a,string b){
	if((a[2]-'0'+1)==b[2]-'0')
		return true;
	else if((a[2]-'0'-1)==b[2])
		return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(check(s1,s2)){
				cout<<1;
				if(check2(s1,s2)){
					cout<<1;
				}else {
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
}
