//GZ-J00500 遵义市第十二中学 梅东耀 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int a=(s1[0]-48)*10+(s1[1]-48);
		int b=(s2[0]-48)*10+(s2[1]-48);
		if(a==b){
			cout<<1;
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')) cout<<1;
			else cout<<0;
		} 
		else cout<<"00";
		if(s1[2]==s2[2]){
			if(abs(a-b)==1) cout<<1;
			else cout<<0;
		}
		else if(a==b){
			if(s1[2]=='C'&&s2[2]=='D') cout<<0;
			else if(abs(s1[2]-s2[2])==1) cout<<1;
			else cout<<0;
		}
		else cout<<0;
	} 
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
