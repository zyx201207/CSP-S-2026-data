//GZ-J00194 遵义市第十九中学 向博熙 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int p=1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 && c1!="01" && c1!="16" && c2!="01" && c2!="16"){
		cout<<1;
	}else{
		cout<<0;
	}  
	for(int i=0;i<=1;i++){
		if(s1[i]==s2[i]){
			p=1;
		}else{
			p=0;
		}
	}
	if(p==1 && s1[2]!=s2[2]){
		cout<<1;
		if((s1[2]=='A' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='A')||(s1[2]=='B' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='A' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='A')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D') && s1[2]!=s2[2]){
			cout<<1;	
		}else{
			cout<<0;
		}if((s1[2]=='A' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='A')||(s1[2]=='B' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D')){
				cout<<1;
			}else{
				cout<<0;
			}
	}else{
		cout<<0<<0<<0;
	}
	

	return 0;
}
