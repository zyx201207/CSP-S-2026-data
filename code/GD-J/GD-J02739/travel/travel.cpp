#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s2==c2){
		cout<<"0000";
		return 0;
	}
	if(s1==c1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s2[1]==c2[1]&&s2[0]==c2[0]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(s2[1]==c2[1]&&s2[0]==c2[0]){
		if((s2[2]>='A'&&c2[2]>='A')&&(s2[2]<='C'&&c2[2]<='C')||(s2[2]<='F'&&c2[2]<='F')&&(s2[2]>='D'&&c2[2]>='D')){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	if(s2[2]==c2[2]||c2[1]==s2[1]){
		if(s2[2]>='A'||c2[2]>='A'){ 
			if(s2[1]-1==c2[1]||s2[1]+1==c2[1]||s2[2]-1==c2[2]||s2[2]+1==c2[2]){
				cout<<1;
				return 0;
			}
			if((s2[2]=='C'&&c2[2]=='D')||(s2[2]=='D'&&c2[2]=='C')){
				cout<<0;
				return 0;
			}
			else{
				cout<<0;
				return 0;
			}
		}

	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}


