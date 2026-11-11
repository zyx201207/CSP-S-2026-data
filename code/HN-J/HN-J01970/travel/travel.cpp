#include<bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	int l;
	char s2;
	string s;
};
P a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a.s>>a.l>>a.s2>>b.s>>b.l>>b.s2;
	if(a.s==b.s){
		if(a.l==b.l){
			if(((a.s2=='A'||a.s2=='B'||a.s2=='C')&&(b.s2=='A'||b.s2=='B'||b.s2=='C'))||((a.s2=='D'||a.s2=='F')&&(b.s2=='D'||b.s2=='F'))){
				if(a.s2=='A'&&b.s2=='B'){
					cout<<"1111";
				}else if(a.s2=='B'){
					if(b.s2=='A'||b.s2=='C'){
						cout<<"1111";
					}
				}else if(a.s2=='C'&&b.s2=='B'){
					cout<<"1111";
				}else if(a.s2=='D'&&b.s2=='F'){
					cout<<"1111";
				}else if(a.s2=='F'&&b.s2=='D'){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
