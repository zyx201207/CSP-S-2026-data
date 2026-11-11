#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
void solve(){
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000"<<endl;
		return;
	}
	else cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000"<<endl;
		return;
	}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
		cout<<1;
	}
	else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
		cout<<1;
	}
	else{
		cout<<"00"<<endl;
		return; 
	}
	if(abs((b[2]-'A')-(d[2]-'A'))==1) cout<<1;
	else cout<<0<<endl;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
