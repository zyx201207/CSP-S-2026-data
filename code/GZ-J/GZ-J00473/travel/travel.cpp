//GZ-J00473 遵义市第四初级中学 陈昊然 
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool vis;
char a,b;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	a=s1[s1.size()-1];
	b=s2[s2.size()-1];
	for(int i=0; i<=s1.size()-2; i++) {
		if(s1[i]!=s2[i]) {
			vis=1;
		}
	}
	if(vis==1) {
		cout<<"000";
		return 0;
	}else cout<<1;
	if(a<='C'&&b<='C'||a>='D'&&b>='D') cout<<1;
	else cout<<0;
	if(a<='C'&&b<='C') {
		if(a+1==b+0) cout<<1;
		else cout<<0;
	} else {
		if(a=='D'&&b=='F'||a=='F'&&b=='D') cout<<1;
		else cout<<0;
	}
	return 0;
}

