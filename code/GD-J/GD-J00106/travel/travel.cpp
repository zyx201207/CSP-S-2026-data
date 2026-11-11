#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char q=s1[2],w=s2[2];
	if((q<='C'&&q>='A'&&w<='C'&&w>='A')||(q<='E'&&q>='D'&&w<='E'&&w>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(char(q+1)==w||char(w+1)==q){
		if((q=='C'&&w=='D')||(q=='D'&&w=='C')){
			cout<<"0";
		}else{
			cout<<"1";
		}
	}else{
		cout<<0;
	}
}
