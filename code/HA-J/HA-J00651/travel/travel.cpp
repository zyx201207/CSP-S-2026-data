#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
bool f=true,a=false,l=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
		if(c2[i]!=c4[i]) f=false;
	if(f){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((c2[2]=='A'&&(c4[2]=='B'||c4[2]=='C')) || (c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')) || (c2[2]=='C'&&(c4[2]=='B'||c4[2]=='A')) || (c2[2]=='D'&&c4[2]=='F') || (c2[2]=='F'&&c4[2]=='D')){
		a=true;
	}
	if(a){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((c2[2]=='D'&&c4[2]=='F') || (c2[2]=='F'&&c4[2]=='D') || (c2[2]=='A'&&c4[2]=='B') || (c2[2]=='B'&&(c4[2]=='A'||c4[2]=='C')) || (c2[2]=='C'&&c4[2]=='B')){
		l=true;
	}
	if(l){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
