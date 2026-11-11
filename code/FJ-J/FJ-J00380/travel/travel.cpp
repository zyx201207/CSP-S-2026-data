#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);//¼ÇµÃ¸Ä 
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	bool flag=1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			flag=0;
		}
	}
	if(flag){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char st1=s1[2],st2=s2[2];
	if(st1=='F'){
		st1='E';
	}
	if(st2=='F'){
		st2='E';
	}
	if((st1-'A'<3&&st2-'A'<3)||(st1-'A'>=3&&st2-'A'>=3)){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(st1-'A'-(st2-'A'))==1){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
