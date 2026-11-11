#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>c1>>c2;
	int a=s2[2]-'A'+1;
	int b=c2[2]-'A'+1;
	bool x=(a<4);
	bool y=(b<4);
	if(s1==c1) cout<<1;
	else cout<<0;
	if(s1==c1 && (s2[0]==c2[0] && s2[1]==c2[1])) cout<<1;
	else cout<<0;
	if(s1==c1 && (s2[0]==c2[0] && s2[1]==c2[1]) && x==y) cout<<1;
	else cout<<0;
	if(s1==c1 && (s2[0]==c2[0] && s2[1]==c2[1]) && x==y && (abs(a-b)==1 && !(a==3 && b==4) &&!(a==4 && b==3))){
		cout<<1;
	}else cout<<0;
	return 0;
}
