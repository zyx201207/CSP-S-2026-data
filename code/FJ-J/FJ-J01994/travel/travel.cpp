#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if (c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if (s1.substr(0,2)==s2.substr(0,2)){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if ((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
		cout<<"00";
		return 0;
	}
	else{
		cout<<'1';
	}
	char t1=s1[2],t2=s2[2];
	if ((t1=='A'&&t2=='B')||(t1=='B'&&t2=='A')||(t1=='B'&&t2=='C')||(t1=='C'&&t2=='B')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
