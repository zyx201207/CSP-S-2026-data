#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cl=0;
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		cl++;
		}
	else cout<<"0";
	if(cl==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		cl++;
	}
	else cout<<"0";
	if(s1[2]!='A'&&s2[2]!='C'&&s1[2]!='C'&&s2[2]!='A'){
		if(s1[2]>s2[2]&&s1[2]-s2[2]==3){
			cout<<"0";
		}
		if(s1[2]<s2[2]&&s2[2]-s1[2]==3){
			cout<<"0";
		}
		}
	else if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
			cout<<"0";}
	else if(cl==2){
		cout<<"1";
		cl++;
		}
	else cout<<"0";
	if(cl==3){
		if(s1[2]>s2[2]&&s1[2]-s2[2]==1)cout<<"1";
		if(s1[2]<s2[2]&&s2[2]-s1[2]==1)cout<<"1";}
	else cout<<"0";
	return 0;
}
