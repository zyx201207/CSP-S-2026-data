#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,bb1,bb2;
	string s1;
	string s2;
	cin >>c1>>s1>>c2>>s2;
	if(s1[2]=='A') bb1=1;
	if(s1[2]=='B') bb1=2;
	if(s1[2]=='C') bb1=3;
	if(s1[2]=='D') bb1=4;
	if(s1[2]=='F') bb1=5;
	if(s2[2]=='A') bb2=1;
	if(s2[2]=='B') bb2=2;
	if(s2[2]=='C') bb2=3;
	if(s2[2]=='D') bb2=4;
	if(s2[2]=='F') bb2=5;
	if(c1 == c2) cout<<1;
	else cout<<0;
	if(s1[0] == s2[0]&&s1[1] == s2[1]) cout<<1;
	else cout<<0;
	if(bb1<=3&&bb2<=3){
		cout<<1;
	}
	else if(bb1>=4&&bb2>=4){
		cout<<1;
	}
	else cout<<0;
	if(bb1-bb2 == 1||bb2-bb1 == 1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}
