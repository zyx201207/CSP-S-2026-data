#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=1;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		a=0;
	}
	bool f=1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	bool ok=1;
	if(f==1){
		if(s1[2]=='F'&&s2[2]=='D') cout<<1;
		else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
		else if(s1[2]=='C'&&s2[2]=='B') cout<<1;
		else if(s1[2]=='C'&&s2[2]=='A') cout<<1;
		else if(s1[2]=='B'&&s2[2]=='C') cout<<1;
		else if(s1[2]=='B'&&s2[2]=='A') cout<<1;
		else if(s1[2]=='A'&&s2[2]=='C') cout<<1;
		else if(s1[2]=='A'&&s2[2]=='B') cout<<1;
		else{
			cout<<0;
			ok=0;
		}
	}else{
		ok=0;
		cout<<0;
	}
	if(s1[2]-s2[2]==1&&ok==1) cout<<1;
	else if(s2[2]-s1[2]==1&&ok==1) cout<<1;
	else cout<<0;
	return 0;
}
