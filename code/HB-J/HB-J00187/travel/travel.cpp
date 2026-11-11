#include<bits/stdc++.h>
using namespace std;
string s,t,n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>s>>t;
	if(n==s){
		cout<<"1";
	}
	else{
		cout<<"000";
		if((m[0]==t[0] && m[1]==t[1]) && (((m[2]>='A' && m[2]<='C' && t[2]>='A' && t[2]<='C') && ((m[2]=='B' && t[2]!='B') || (t[2]=='B' && m[2]!='B'))) || (m[2]>='D' && m[2]<='F' && t[2]>='D' && t[2]<='F'))){
			cout<<"1";
		}
		else cout<<"0";
		return 0;
	}
	if(m[0]==t[0] && m[1]==t[1]){
		cout<<"1";
		if((m[2]>='A' && m[2]<='C' && t[2]>='A' && t[2]<='C') || (m[2]>='D' && m[2]<='F' && t[2]>='D' && t[2]<='F')){
			cout<<"1";
		}
		else cout<<"0";
		if(((m[2]>='A' && m[2]<='C' && t[2]>='A' && t[2]<='C') && ((m[2]=='B' && t[2]!='B') || (t[2]=='B' && m[2]!='B'))) || (m[2]>='D' && m[2]<='F' && t[2]>='D' && t[2]<='F')){
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"000";
	return 0;
}
