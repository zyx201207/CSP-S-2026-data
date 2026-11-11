// GZ-J00632 贵阳市第一中学 谭心民 
#include<bits/stdc++.h>
using namespace std;
int c,q;
string s,a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stout);
	cin>>c>>s>>q>>a;
	if(c==q)cout<<"1";
	else {
	cout<<"0000";return 0;}
	if(s[0]==a[0] && s[1]==a[1])cout<<"1";
	else {
		cout<<"000";return 0;
	}
	if(s[2]<='c' && a[2]<='c'){
		if(s[2]-a[2]==-1 || s[2]-a[2]==1){
			cout<<"11";
		}
		else cout<<"10";
	}
	else{
		if(s[2]>='d' && a[2]>='d')cout<<"11";
		else {
			cout<<"00";return 0;
		}
	}
	
	return 0;
} 
