#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int val[10],val2[10];
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	val[0]=val[1]=val[2]=1;
	val[3]=val[5]=2;
	val2[0]=0;
	val2[1]=1;
	val2[2]=2;
	val2[3]=4;
	val2[5]=5;
	if(c1==c2) {
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			cout<<1;
			if(val[s1[2]-'A']==val[s2[2]-'A']) {
				cout<<1;
				if(abs(val2[s1[2]-'A']-val2[s2[2]-'A'])==1) {
					cout<<1;
				} else {
					cout<<0;
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
