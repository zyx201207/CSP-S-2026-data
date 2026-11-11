#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d;
int s[2];
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(c==d) cout<<"1";
	else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1]) cout<<"1"; else cout<<"0";
	for(int p=0;p<=0;p++){
		if(a[2]=='A') s[0]=1;
		if(a[2]=='B') s[0]=1;
		if(a[2]=='C') s[0]=1;
		if(a[2]=='D') s[0]=2;
		if(a[2]=='E') s[0]=2;
	}
	for(int p=0;p<=0;p++){
		if(b[2]=='A') s[1]=1;
		if(b[2]=='B') s[1]=1;
		if(b[2]=='C') s[1]=1;
		if(b[2]=='D') s[1]=2;
		if(b[2]=='E') s[1]=2;
	}
	if(s[0]==s[1]&&a[0]==b[0]&&a[1]==b[1]){
		cout<<"1";
	}
	else cout<<"0";
	if(a[2]-b[2]==1||a[2]-b[2]==-1&&a[0]==b[0]&&a[1]==b[1]) cout<<"1"; else cout<<"0";
	return 0;
} 
