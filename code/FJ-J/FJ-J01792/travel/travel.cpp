#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool f1=0,f2=0;
	if(a!=c){
		cout<<"0000";
		return 0;
	} 
	if(a==c) cout<<"1";
	for(int i=1;i<b.size();i++){
		if(b[i]==d[i]) f1=1;
	}
	if(f1==1) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(b[3]=='A'&&d[3]=='B') f2=1;
	if(b[3]=='A'&&d[3]=='C') f2=1;
	if(b[3]=='B'&&d[3]=='A') f2=1;
	if(b[3]=='B'&&d[3]=='C') f2=1;
	if(b[3]=='C'&&d[3]=='A') f2=1;
	if(b[3]=='C'&&d[3]=='B') f2=1;
	if(b[3]=='D'&&d[3]=='F') f2=1;
	if(b[3]=='F'&&d[3]=='D') f2=1;
	if(f2==1) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((b[3]+'0')-(d[3]+'0')==1||(d[3]+'0')-(b[3]+'0')==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
