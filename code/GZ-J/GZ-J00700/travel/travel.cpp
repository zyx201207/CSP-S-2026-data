//GZ-J00700 陈梓灿 遵义市第四初级中学 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
if(c1[0]==c2[0]&&c1[1]==c2[1]){
	cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
			if(int(char(s1[2]))+1==int(char(s2[2]))||int(char(s2[2]))+1==int(char(s1[2]))&&s1[2]!='C'&&s2[2]!='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else{
		cout<<"000";
		return 0;
	}
}else{
	cout<<"0000";
	return 0;
}

	return 0;
}

