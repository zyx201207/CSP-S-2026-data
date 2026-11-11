#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b,a2,b2,c,c2;
map<char,int>vis;
char s,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vis['A']=vis['B']=vis['C']=1;
	vis['D']=vis['F']=2;
	cin>>a>>b>>a2>>b2;
	if(a==a2){
		cout<<"1";
		c+=b[0];
		c+=b[1];
		c2+=b2[0];
		c2+=b2[1];
		if(c==c2) {
			cout<<"1";
			if(vis[b[2]]==vis[b2[2]]) {
				cout<<"1";
				if(b[2]+1==b2[2]||b[2]-1==b2[2]) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}

