#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string c1,s1,c2,s2;
	int a=0,b=-1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
	cout<<1;
	}
	else {
		cout<<"0000";
    	return 0;
		}

	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		a=1;
	}
	else{
		cout<<"000";
		return 0;
	}
	
	if(a==1){
		if((s1[2]=='D'||s2[2]=='D')&&(s1[2]=='E'||s2[2]=='E')) {
		cout<<1;
		b=1;
		}
		else if((s1[2]=='D'||s2[2]=='D')||(s1[2]=='E'||s2[2]=='E')) {
		cout<<0;
		b=2; 
	}
		else cout<<1;
	}
	else {
		cout<<0;
	}
	
	if (b==1) cout<<1;
	else if(b==2) cout<<0;
	else{
		if((s1[2]=='A'||s2[2]=='A')&&(s1[2]=='C'||s2[2]=='C')) cout<<0;
		else {cout<<1;}
    }
	return 0;
}
