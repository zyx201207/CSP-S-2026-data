#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
string s;
int ac,as,bc,bs;
char ax,bx;

void solve(){
	cin>>ac;
	cin>>s;
	as=s[0]-'0';
	as*=10;
	as+=s[1]-'0';
	ax=s[2];
	
	cin>>bc;
	cin>>s;
	bs=s[0]-'0';
	bs*=10;
	bs+=s[1]-'0';
	bx=s[2];

	if(ac==bc){
		cout<<"1";
		if(as==bs){
			cout<<"1";
			if('A'<=ax&&ax<='C'&&'A'<=bx&&bx<='C'){
				cout<<"1";
				if(ax=='A'&&bx=='C')cout<<'0';
				else if(bx=='A'&&ax=='C') cout<<'0';
				else cout<<'1';
			}else if('D'<=ax&&ax<='F'&&'D'<=bx&&bx<='F'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return;
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int TTT=1;
//	cin>>TTT;
	while(TTT--){
		solve();
	}
}