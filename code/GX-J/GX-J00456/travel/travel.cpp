#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	//first
	if(c1==c2) {
		cout<<1;
		//second
		bool flag = false;
		for(int i=0;i<2;++i){
			if(s1[i]!=s2[i]){
				flag = true;
				cout<<0;
				break;
			}
		}
		if(flag == false){cout<<1;}
		if(flag == false){
			//third
			if(s1[2] >='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') cout<<1;
			else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') cout<<1;
			else cout<<0;
			//last
			if(s1[2]=='D'&&s2[2]=='C') cout<<0;
			else if(s1[2]=='C'&&s2[2]=='D') cout<<0;
			else if(s1[2]+1 == s2[2] || s2[2]+1 == s1[2] ) cout<<1;
			else cout<<0;
		}
		else cout<<0<<0;
	}
	else {cout<<0<<0<<0<<0;}
	return ;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N = 1;
	while(N--) solve();
	return 0;
}
