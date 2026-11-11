#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios:sync_
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;
		a = 1;
		if(s1[2]=='D' and s2[2]=='E'  or  s1[2]=='A' and s2[2]=='B'  or  s1[2]=='B' and s2[2]=='C'  or  s1[2]=='A' and s2[2]=='C'){
			cout<<1;
		}else if(s2[2]=='D' and s1[2]=='E'  or  s2[2]=='A' and s1[2]=='B'  or  s2[2]=='B' and s1[2]=='C'  or  s1[2]=='C' and s2[2]=='A'){
			cout<<1;
		}else cout<<0;
	}else {
		cout<<0<<0;
		a = 0;
	}
	if(s1[2]=='D' and s2[2]=='E'  or  s1[2]=='A' and s2[2]=='B'  or  s1[2]=='B' and s2[2]=='C'){
		if(a==1){
			cout<<1;
		}else cout<<0;
		}else if(s2[2]=='D' and s1[2]=='E'  or  s2[2]=='A' and s1[2]=='B'  or  s2[2]=='B' and s1[2]=='C'){
			if(a==1) {
				cout<<1;
			}else cout<<0;
		}
	else cout<<0;
	return 0;
}
