//GZ-J00462 遵义市第十一中学 祝家懿 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,n=0;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		n++;
		cout<<1;
	} 
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		n++;
	} 
	else cout<<0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			n++;
			cout<<1;
		}
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			n++;
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else cout<<0;
	if(n==3){
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
