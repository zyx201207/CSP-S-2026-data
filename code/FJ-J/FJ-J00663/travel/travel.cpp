#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a1+=(c1[i]-'0');
		a2+=(c2[i]-'0');
	}
	if(a1==a2){cout<<"1";}
	else{
		cout<<"0000";
		return 0;
	}//p1
	for(int i=0;i<=1;i++){
		a1+=(s1[i]-'0');
		a2+=(s2[i]-'0');
	}
	if(a1==a2){cout<<"1";}
	else{
		cout<<"000";
		return 0;
	}//p2
	if(s1[2]>='A' && s1[2]<='C'){
		if(s2[2]>='A' && s2[2]<='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[2]=='D' || s2[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}//p3
	if((s1[2]=='A' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='A')){
		cout<<"0";
		return 0;
	}else{
		cout<<"1";
	}//p4
	return 0;
}
