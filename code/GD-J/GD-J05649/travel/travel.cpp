#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b,c,d;
	bool e[3];
	for(int i=0;i<4;i++){
		e[i]=false;
	}
	freopen("travel.in","r",stdin);
	cin>>a>>b>>c>>d;
	if(a==c){
		e[0]=true;
	}
	if(b.first==d.first&&b.second==d.second){
		e[1]=true;
	}
	if(e[1]){
		if(b.end-'0'==d.end-'0'-1&&d.end-'0'!=46||b.end-'0'-1==d.end-'0'&&b.end-'0'!=46){
			e[3]=true;
		}
	}
	if(e[3]){
		e[2]==true;
	}
	if(b.end-'0'==d.end-'0'-1&&d.end-'0'!=46||b.end-'0'-1==d.end-'0'&&b.end-'0'!=46||b.end-'0'==43&&d.end-'0'==45||b.end-'0'==45&&d.end-'0'==43){
		if(e[1]){
			e[2]=true;
		}
	}
	freopen("travel.out","r",stdout);
	for(int i=0;i<4;i++){
		if(e[i]){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	fclose stdin;
	fclose srdout;
} 
