#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	ans="0000";
	if(a==c){
		ans[0]='1';
		if(b[1]==d[1]){
			ans[1]='1';
			if(b[2]<='C'&&d[2]<='C'){
				ans[2]='1';
				if(b[2]=='C'&&d[2]=='B') ans[3]='1';
				else if(b[2]=='B'&&d[2]=='C') ans[3]='1';
				else if(b[2]=='B'&&d[2]=='A') ans[3]='1';
				else if(b[2]=='A'&&d[2]=='B') ans[3]='1';
			}else if(b[2]>='D'&&d[2]>='D'){
				ans[2]='1';
				if(b[2]=='D'&&d[2]=='F') ans[3]='1';
				else if(b[2]=='F'&&d[2]=='D') ans[3]='1';
			}
		}
	}cout<<ans;
} 
