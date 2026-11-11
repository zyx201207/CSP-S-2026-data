#include<bits/stdc++.h>
using namespace std;

int c1,c2;
string s1,s2;
bool f,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	f=f2=f3=f4=false;
 	if(c1==c2) f=true;
	if(f) if(s1[0]==s2[0] && s1[1]==s2[1]) f2=true;
	if(f2){
		if((s1[2]=='A' || s1[2]=='B' || s1[2]=='C') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) f3=true;
		if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F')) f3=true;
	}
	if(f3){
		if(s1[2]=='A' && s2[2]=='B') f4=true;
		if(s1[2]=='B' && s2[2]=='C') f4=true;
		if(s1[2]=='C' && s2[2]=='B') f4=true;
		if(s1[2]=='B' && s2[2]=='A') f4=true;
		
		if(s1[2]=='D' && s2[2]=='F') f4=true;
		if(s1[2]=='F' && s2[2]=='D') f4=true;
	}
	
	if(f4) cout<<"1111"<<endl;
	else if(f3) cout<<"1110"<<endl;
	else if(f2) cout<<"1100"<<endl;
	else if(f) cout<<"1000"<<endl;
	else cout<<"0000"<<endl;
	
	return 0;
}

