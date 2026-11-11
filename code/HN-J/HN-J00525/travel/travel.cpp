#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	bool f=0,f2=0,f3=0,f4=0;
	cin>>c1>>s1>>c2>>s2;	
	f=(c1==c2);
	if(f==0){
		cout<<"0000\n";
		return 0;
	}
	cout<<f;
	f2=(s1.substr(0,2)==s2.substr(0,2)&&f);
	if(f2==0){
		cout<<"000\n";
		return 0;
	}
	cout<<f2;	
	f3=((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&s1[2]!=s2[2]&&f2);
	if(f3==0){
		cout<<"00\n";
		return 0;
	}
	cout<<f3;
	f4=(((s1[2]>='A'&&s1[2]<='C'&&(s2[2]==s1[2]+1||s2[2]==s1[2]-1))||((s1[2]=='D'||s1[2]=='F')&&f3))&&f3);
	if(f4==0){
		cout<<"0\n";
		return 0;
	}
	cout<<f4<<'\n';
	return 0;
}
