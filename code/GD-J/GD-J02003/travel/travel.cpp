#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,ans;
int a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<c2;
	if(c1==c2){
		cout<<'1';
		a++;
		//ans[0]='1';
	}
	else {
		//ans=;
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<'1';
		a++;
	}
	else{
		//ans+;
		cout<<"000";
		return 0;
	}
	if((s1[2]<'D' and s2[2]<'D') or (s1[2]>'C' and s2[2]>'C')){
		cout<<'1';
		a++;
	}
	else{
		//ans+;
		cout<<"00";
		return 0;
	}
	if(s1[2]=='B' and (s2[2]=='A' or s2[2]=='C')){
		cout<<'1';
		a++;
	}
	if((s2[2]=='B' and (s1[2]=='A' or s1[2]=='C'))){
		cout<<'1';
		a++;
	}
	if ((s1[2]=='D' and s2[2])=='E'){
		cout<<'1';
		a++;
	}
	if((s2[2]=='D' and s1[2])=='E'){
		a++;
		cout<<'1';
	}
	if(a==3)
		cout<<'0';
	//cout<<ans;
	return 0;
}
