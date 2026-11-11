#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<0000;
		return 0;
	}
	if(s1[1]!=s2[1]||s1[2]!=s2[2]){
		cout<<1000;
		return 0;
	}
	if(abs(s1[3]-s2[3])>2){
		cout<<1100;
		return 0;
	}
	if(s1[3]<='C'&&s2[3]>='D'){
		cout<<1100;
		return 0;
	}
	if(s2[3]<='C'&&s1[3]>='D'){
		cout<<1100;
		return 0;
	}
	if(abs(s1[3]-s2[3])!=1){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}
/*
guan yv yi dao shui ti ying kong wo 45 fen zhong zhe hui shi
wo wu yi shi nan kan de
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
qwq
*/
