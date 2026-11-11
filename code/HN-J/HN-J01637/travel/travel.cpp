#include<bits/stdc++.h>
using namespace std;
char s1,s2;
int c1,c2,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>r>>s1;
	cin>>c2>>x>>s2;
	if(c1==c2) cout<<'1';
	else {cout<<"0000";return 0;}
	if(r==x){
		cout<<"1";
		if(s1<='C'&&s2<='C'){
			cout<<"1";
			if(s1=='B'||s2=='B') cout<<"1";
			else cout<<"0";
		}else if(s1>'C'&&s2>'C'){
			cout<<"11";
		}else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
