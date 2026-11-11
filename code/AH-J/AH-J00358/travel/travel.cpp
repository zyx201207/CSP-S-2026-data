#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2,a1,a2;
	int t=0;
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		a1=1;
	}
	else{
		a1=2;
	}
	if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
		a2=1;
	}
	else{
		a2=2;
	}
	if(c1==c2){
		cout<<1;
		t++;
	} 
	else{
		cout<<0;
	}
    if(s1[0]-48+s1[1]-48==s2[0]-48+s2[1]-48 && t==1){
		cout<<1;
		t++;
	}
	else{
		cout<<0;
	}
	if((t==2)&&(a1==a2)){
	cout<<1;
	t++;
	}
	else{
		cout<<0;
	}
	if(t==3 && (s1[2]==s2[2]+1 ||s1[2]+1==s2[2] )){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
