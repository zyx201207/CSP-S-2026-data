#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool pda=(c1==c2);
	bool pdb=(pda&&(s1[0]==s2[0]&&s1[1]==s2[1]));
	bool pdc=(pda&&pdb&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]=='D'&&s2[2]=='F')&&(s1[2]=='F'&&s2[2]=='D'))));
	bool pdd;
	if(s1[2]=='A'){
		if(s2[2]=='B') pdd=1;
		else pdd=0;
	}else if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C') pdd=1;
		else pdd=0;
	}else if(s1[2]=='C'){
		if(s2[2]=='B') pdd=1;
		else pdd=0;
	}else if(s1[2]=='D'){
		if(s2[2]=='F') pdd=1;
		else pdd=0;
	}else if(s1[2]=='F'){
		if(s2[2]=='D') pdd=1;
		else pdd=0;
	}
	pdd=(pda&&pdb&&pdc&&pdd);
	cout<<pda<<pdb<<pdc<<pdd;
	return 0;
}
