#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s1;
	cin>>m>>s2;
	if(n==m){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='D')) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	} 
 else cout<<0<<0<<0<<0;
	return 0;
}
