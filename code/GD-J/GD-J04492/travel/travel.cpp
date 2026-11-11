#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool b=0;
	int s3=1,s4=1;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]) b=1;
		else b=0;
	}
	if(b==1) cout<<"1";
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D') cout<<"1"; 
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(s1[3]-s2[3]-'A'==1||s2[3]-s1[3]-'A'==1) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
