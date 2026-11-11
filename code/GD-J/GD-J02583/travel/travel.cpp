#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int s1n=0,s2n=0;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') s1n=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2n=1;
			if(s1[2]=='D'||s1[2]=='F') s1n=2;
			if(s2[2]=='D'||s2[2]=='F') s2n=2;
			if(s1n==s2n){
				cout<<1;
				if(s1[2]=='A') s1n=1;
				if(s1[2]=='B') s1n=2;
				if(s1[2]=='C') s1n=3;
				if(s1[2]=='D') s1n=4;
				if(s1[2]=='F') s1n=5;
				if(s2[2]=='A') s2n=1;
				if(s2[2]=='B') s2n=2;
				if(s2[2]=='C') s2n=3;
				if(s2[2]=='D') s2n=4;
				if(s2[2]=='F') s2n=5;
				if(abs(s1n-s2n)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
