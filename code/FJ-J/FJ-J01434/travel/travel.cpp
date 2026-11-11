#include<bits/stdc++.h>
using namespace std;
#define int long long

int _, n;
string s1,s2,s3,s4;

void solve(){
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<"1";
	else{
		cout<<"0000";
		return;
	}
	int op=(s2[0]-'0')*10+s2[1]-'0';
	int po=(s4[0]-'0')*10+s4[1]-'0';
	int jk=s2[2]-'A';
	int kj=s4[2]-'A';
	if(op==po){
		cout<<"1"; 
	}
	else{
		cout<<"000";
		return;
	}
	if((jk<=2&&kj<=2)||(jk>2&&kj>2)){
		cout<<"1";
	}
	else{
		cout<<"00";
		return;
	}
	if(jk<=2){
		int uu=abs(jk-kj);
		if(uu==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"1";
	}
}

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_ = 1;
	while(_--){
		solve();
	}
}
