#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	int s1a=s1[0]-'0';
	int s1b=s1[1]-'0';
	int s2a=s2[0]-'0';
	int s2b=s2[1]-'0';
	int s1z=s1a*10+s1b;
	int s2z=s2a*10+s2b;
	bool ok1=0;
	if(s1z==s2z){
		ok1=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	bool ok2=0;
	if(ok1&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D'))){
		ok2=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(ok2
	&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	return 0;
}
