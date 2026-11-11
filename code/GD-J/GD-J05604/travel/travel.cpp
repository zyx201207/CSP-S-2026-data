#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,p1="",p2="";
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D')s1[2]='E';
	if(s2[2]=='D')s2[2]='E';
	for(int i=0;i<2;i++){
		p1+=s1[i];
		p2+=s2[i];
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='E'&&s2[2]>='E'))){
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1)cout<<"1111";
	else cout<<"1110";
	return 0;
}
