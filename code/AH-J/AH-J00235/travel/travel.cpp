#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	string c1,s1,p1="",c2,s2,p2="";
	cin>>c1>>s1>>c2>>s2;
	for(i=0;i<2;i++){
		p1+=s1[i];
		p2+=s2[i];
	}
	if(c1!=c2){
		cout<<"0000";
	}else if(p1!=p2){
		cout<<"1000";
	}else if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<"1111";
		}else{
			cout<<"1100";
		}
	}else{
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<"1100";
		}else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
			cout<<"1110";
		}else{
			cout<<"1111";
		}
	}
	return 0;
}
