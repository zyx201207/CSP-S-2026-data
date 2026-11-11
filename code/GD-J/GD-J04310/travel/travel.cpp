#include<bits/stdc++.h>
using namespace std;
long long a1,b1;
int main(){
char a2[3],b2[3];
	cin.tie(0)->sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;	
	if(a1==b1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){
		cout<<1;

	}
	else{
		cout<<0;
	}
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){
		if(a2[2]=='A'&&b2[2]=='B') cout<<1;
		else if(a2[2]=='A'&&b2[2]=='C') cout<<1;
		else if(a2[2]=='B'&&b2[2]=='A') cout<<1;
		else if(a2[2]=='B'&&b2[2]=='C') cout<<1;
		else if(a2[2]=='C'&&b2[2]=='B') cout<<1;
		else if(a2[2]=='C'&&b2[2]=='A') cout<<1;
		else if(a2[2]=='D'&&b2[2]=='F') cout<<1;
		else if(a2[2]=='F'&&b2[2]=='D') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]){
	if(a2[2]=='A'&&b2[2]=='B') cout<<1;
		else if(a2[2]=='B'&&b2[2]=='A') cout<<1;
		else if(a2[2]=='B'&&b2[2]=='C') cout<<1;
		else if(a2[2]=='C'&&b2[2]=='B') cout<<1;
		else if(a2[2]=='D'&&b2[2]=='F') cout<<1;
		else if(a2[2]=='F'&&b2[2]=='D') cout<<1;
		else cout<<0;}
		else cout<<0;
	return 0;
} 
