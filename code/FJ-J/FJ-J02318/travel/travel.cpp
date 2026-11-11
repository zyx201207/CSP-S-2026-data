#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a,c;
string b,d;
void solve(){
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		//
		char e,f;
		e=b[b.size()-1];
		f=d[d.size()-1];
		b[b.size()-1]=' ';
		d[d.size()-1]=' ';
		if(b==d){
			cout<<1;
			if(e<='C'&&f<='C'){
				cout<<1;
				if(e=='A'&&f=='C'||e=='C'&&f=='A'){
					cout<<0;
				}else{
					cout<<1;
				} 
			}else if(e>='D'&&f>='D'){
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
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
