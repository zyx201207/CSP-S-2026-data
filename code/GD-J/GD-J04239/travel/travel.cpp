#include<bits/stdc++.h>
using namespace std;
char lr(char x){
	if(x=='D'|| x=='F'){
		return 'r'; 
	}else{
		return 'l';
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;//是否同一车厢 
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1])cout<<1;//是否为同一排 
	else {
		cout<<"000";
		return 0;
	}
	bool flag=lr(s1[2])==lr(s2[2]);
	
	if(flag)cout<<1;//是否为同一侧 
	else cout<<0;
	
	if(flag){//同侧才能相邻 
		if(s1[2]=='D' && s2[2]=='F'){
			cout<<1;
			return 0;
		}
		if(abs( (s1[2]-'0') - (s2[2]-'0') )==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	cout<<flush;
	return 0;
}
