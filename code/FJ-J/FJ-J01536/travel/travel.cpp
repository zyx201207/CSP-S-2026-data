#include<bits/stdc++.h>
using namespace std;
int main(){
	freoprn("travel.in","r",stdin);
	freoprn("travel.out","w",stdout);
	long long ans=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((int(s1[2])<='C'&&int(s2[2])>='D')||(int(s1[2])>='D'&&int(s1[2])<='C')){
		cout<<"00";
		return 0;
	}else cout<<"1";
	if(abs(int(s1[2])-int(s2[2]))==1){
		cout<<"1";
	}else cout<<"0";
	return 0;
} 
