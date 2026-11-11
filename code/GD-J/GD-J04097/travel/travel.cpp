#include<bits/stdc++.h> 
using namespace std;
string c,r,s,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>r>>s>>x;
	if(c==s) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(r[0]==x[0]&&r[1]==x[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(r[2]<='C'&&x[2]<='C') cout<<1;
	else if(r[2]>'C'&&x[2]>'C'){
		cout<<11;
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(r[2]==x[2]+'1'||r[2]==x[2]-'1') cout<<1;
	else{
		cout<<0;
	}
	return 0;
}
