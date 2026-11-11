#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool e=false;
	if(c1==c2){
		cout<<"1";
		e=true;
	}else{
		cout<<"0";
	}
	bool f=false;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&e==true){
		cout<<"1";
		f=true;
	}else{
		cout<<"0";
	}
	bool d=false;
	if(((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&f==true){
		cout<<"1";
		d=true;
		
	}else{
		cout<<"0";
	}
	int a=s1[2],b=s2[2];
	if(((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))||(d==true&&abs(a-b)==1)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
