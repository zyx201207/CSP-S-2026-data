#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
string s,c;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s>>m>>c;
	if(n!=m)cout<<0<<0<<0<<0;
	else{
		cout<<1;
		if(s[1]==c[1]&&s[0]==c[0]){
			cout<<1;
			if(s[2]!='D'&&s[2]!='F'&&c[2]!='D'&&c[2]!='F'||s[2]=='D'&&s[2]=='F'&&c[2]=='D'&&c[2]=='F'){
				cout<<1;
				if(abs((s[2]-'0')-(c[2]-'0'))==1)cout<<1;
				else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}
	return 0;
}
