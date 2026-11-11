#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2,s1=0,s2=0;char ss1[4],ss2[4];
	cin>>c1;
	cin>>ss1;
	cin>>c2;
	cin>>ss2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	for(int i=0;i<2;i++){
		s1=s1*10+(ss1[i]-'0');
		s2=s2*10+(ss2[i]-'0');
	}
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(ss1[2]>='A'&&ss2[2]<='C'&&ss2[2]>='A'&&ss2[2]<='C'){
		cout<<"1";
	}
	else if(ss1[2]>='D'&&ss2[2]<='F'&&ss2[2]>='D'&&ss2[2]<='F'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((abs((ss1[2]-'0')-(ss2[2]-'0'))==1)||(ss1[2]=='D'&&ss2[2]=='F')||(ss1[2]=='F'&&ss2[2]=='D')){
		cout<<1;
		return 0;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
