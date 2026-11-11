#include<bits/stdc++.h>
using namespace std;
string s,ss;
char c[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>c[1]>>c[2]>>c[3]>>ss>>c[4]>>c[5]>>c[6];
	if(s==ss)cout<<1;
	else cout<<0;
	if(c[1]==c[4]&&c[2]==c[5])cout<<1;
	else cout<<0;
	if(c[1]==c[4]&&c[2]==c[5]){
		if(c[3]=='A'){
			if(c[6]=='B'||c[6]=='C')cout<<1;
			else cout<<0;
		}else if(c[3]=='B'){
			if(c[6]=='A'||c[6]=='C')cout<<1;
			else cout<<0;
		}else if(c[3]=='C'){
			if(c[6]=='B'||c[6]=='A')cout<<1;
			else cout<<0;
		}else if(c[3]=='D'){
			if(c[6]=='F')cout<<1;
			else cout<<0;
		}else if(c[3]=='F'){
			if(c[6]=='D')cout<<1;
			else cout<<0;
		}
	}else cout<<0;
	if(c[1]==c[4]&&c[2]==c[5]){
		if(c[3]=='A'){
			if(c[6]=='B')cout<<1;
			else cout<<0;
		}
		if(c[3]=='B'){
			if(c[6]=='A'||c[6]=='C')cout<<1;
			else cout<<0;
		}
		if(c[3]=='C'){
			if(c[6]=='B')cout<<1;
			else cout<<0;
		}
		if(c[3]=='D'){
			if(c[6]=='F')cout<<1;
			else cout<<0;
		}
		if(c[3]=='F'){
			if(c[6]=='D')cout<<1;
			else cout<<0;
		}
	}
}  
