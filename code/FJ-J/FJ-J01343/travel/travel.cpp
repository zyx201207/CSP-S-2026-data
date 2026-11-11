#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int sp1=(s1[0]-'0')*10+(s1[1]-'0');
	int sp2=(s2[0]-'0')*10+(s2[1]-'0');
	bool flag1=false, flag2=false;
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B' || s2[2]=='C'){
			flag1=true;
		}
	}else{
		if(s2[2]=='D' || s2[2]=='F'){
			flag1=true;
		}
	}
	
	if(s1[2]=='A'&&s2[2]=='B'){
		flag2=true;
	}
	if(s1[2]=='B'&&(s2[2]=='A' || s2[2]=='C')){
		flag2=true;
	}
	if(s1[2]=='C'&&s2[2]=='B'){
		flag2=true;
	}
	if(s1[2]=='D'&&s2[2]=='F'){
		flag2=true;
	}
	if(s1[2]=='F'&&s2[2]=='D'){
		flag2=true;
	}
	
//	cout<<sp1<<" "<<sp2<<"\n";
	if(c1!=c2){
		cout<<"0000";
	}else if(sp1!=sp2){
		cout<<"1000";
	}else if(!flag1){
		cout<<"1100";
	}else if(!flag2){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
