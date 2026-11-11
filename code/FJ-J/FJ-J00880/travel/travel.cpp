#include<bits/stdc++.h>
using namespace std;
string s="ABC DF";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<(c1==c2);
	bool b=true;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			b=false;
			break;
		}
	}
	if(!b){
		cout<<"000";
		return 0;
	}
	cout<<b;
	if(!((s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')||(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'))){
		cout<<"00";
		return 0;
	}
	cout<<((s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D')||(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'));
	int p=0,pp=0;
	for(int i=0;i<6;i++){
		if(s[i]==s1[2]){
			p=i;
		}
		if(s[i]==s2[2])pp=i;
	}
	if(abs(pp-p)==1)cout<<1;
	else cout<<0;
	
	return 0;
} 
