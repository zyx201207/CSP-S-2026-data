#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>c1>>s2>>c2;
	t1=c1.substr(0,2);
	t2=c2.substr(0,2);
	if(s1!=s2){
		cout<<"0000";
		return 0;
	}
	if(t1!=t2){
		cout<<"1000";
		return 0;
	}
	if(((c1[2]=='B'||c1[2]=='A'||c1[2]=='C')&&(c2[2]=='B'||c2[2]=='A'||c2[2]=='C'))||(c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D')){
		cout<<"111";
		if((c1[2]=='D'&&c2[2]=='F')||(c1[2]=='F'&&c2[2]=='D')||(c1[2]=='A'&&c2[2]=='B')||(c1[2]=='B'&&c2[2]=='C')||(c1[2]=='B'&&c2[2]=='A')||(c1[2]=='C'&&c2[2]=='B')){cout<<"1";}
		else{cout<<"0";}
		return 0;
	}
	else{cout<<"1100";}
	return 0;
}
