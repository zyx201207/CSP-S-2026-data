#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,z1,z2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	z1=s1[2];z2=s2[2];
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if(z1<=67&&z1>=65&&z2<=67&&z2>=65){
			cout<<1;
			if(z1-z2==1||z2-z1==1)cout<<1;
			else cout<<0;
		}
		else{
		if(z1<=69&&z1>=68&&z2<=69&&z2>=68){
			cout<<"11";
		}
		else cout<<0;
		}
	}
	//c1='C';
	//cout<<s1[1];
	return 0;
}
