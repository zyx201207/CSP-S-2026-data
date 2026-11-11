#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=0,a2=0;
	for(int i=0;i<2;i++){
		a1=a1*10+c1[i]-'0';
		a2=a2*10+c2[i]-'0';
	}
	if(a1==a2)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	a1=0;
	a2=0;
	for(int i=0;i<2;i++){
		a1=a1*10+s1[i]-'0';
		a2=a2*10+s2[i]-'0';
	}
	if(a1==a2)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	a1=int(s1[2])-'A'+1;
	a2=int(s2[2])-'A'+1;
	if(a1>3&&a2<=3||a1<=3&&a2>3){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(abs(a1-a2)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	
	return 0;
} 
