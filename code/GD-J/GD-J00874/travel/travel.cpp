#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2)?1:0;
	cout<<(s1[0]==s2[0]&&s1[1]==s2[1])?1:0;
	if(s1[2]<='C'){
		if(s2[2]<='C'){
			cout<<1;
			if((s2[2]+'C'-'B')==s1[2]||(s2[2]-('C'-'B'))==s1[2]) cout<<1;
			else cout<<0;
		} else cout<<0<<0;
	} else{
		if(s2[2]>='D'){
			cout<<1;
			if((s2[2]+'C'-'B')==s1[2]||(s2[2]-('C'-'B'))==s1[2]) cout<<1;
			else cout<<0;
		} else cout<<0<<0;
	}
//	cout<<' '<<s1<<' '<<s2[2]+'C'-'B';
	return 0;
}
