#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==c2[0]&&s2[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s2[2]<='C'&&c2[2]<='C')||(s2[2]>='D'&&c2[2]>='D')){
		cout<<"1";
		if(s2[2]<='C'&&c2[2]<='C'){
			f=1;
		}else{
			f=2;
		}
	}else{
		cout<<"00";
		return 0;
	}
	if(f==2){
		cout<<"1";
	}else if(f==1&&(s2[2]-c2[2])==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
