#include<bits/stdc++.h>
using namespace std;
void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return ;
	}
	string ss1,ss2;
	for(int i=0;i<s1.size()-1;i++){
		ss1+=s1[i]; 
	} 
	for(int i=0;i<s2.size()-1;i++){
		ss2+=s2[i]; 
	} 
	if(ss1==ss2){
		cout<<1;
	}
	else{
		cout<<"000";
		return ;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return ;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
