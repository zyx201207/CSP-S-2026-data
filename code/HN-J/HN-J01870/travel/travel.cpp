#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<'1';
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<"000";
		return 0;
	}
	cout<<'1';
	char t=s1[2],tt=s2[2];
	if(t<tt)swap(t,tt);
	if((t=='E'&&tt=='D')||t=='C'||tt=='A')cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if((t=='E'&&tt=='D')||(t=='B'&&tt=='A')||(t=='C'&&tt=='B'))cout<<'1';
	else cout<<'0';
	return 0;
}

