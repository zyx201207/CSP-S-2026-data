#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c1,c2;
string s1,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	int d1=stoi(s1.substr(0,2)),d2=stoi(s2.substr(0,2));
	if(c1!=c2) { cout<<"0000\n"; return; }
	if(d1!=d2) { cout<<"1000\n"; return; }
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||
	  (((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')))) { cout<<"1100\n"; return; }
	if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')) { cout<<"1110\n"; return; }
	cout<<"1111\n";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

/*
  8:47
  还可以，直接 if/else 就行了
*/
