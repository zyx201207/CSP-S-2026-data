#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,h;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000\n";
		return 0;
	}
	bool p=1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) p=0;
	}
	if(p==1) cout<<"1";
	else{
		cout<<"000\n";
		return 0;
	}
	if((s1[2]=='C' && s2[2]=='D') || (s1[2]=='D' && s2[2]=='C')){
		cout<<"00\n";
		return 0;
	}
	else cout<<"1";
	if((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')){
		cout<<"0\n";
	}
	else cout<<"1\n";
	return 0;
}
