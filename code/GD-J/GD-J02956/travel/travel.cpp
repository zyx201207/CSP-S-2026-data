#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,t,ans="0000";
	cin>>a>>s>>b>>t;
	if(a==b){
		ans[0]='1';
		if(s[0]==t[0]&&s[1]==t[1]){
			ans[1]='1';
			if(s[2]<='C'&&t[2]<='C'||s[2]>='D'&&t[2]>='D'){
				ans[2]='1';
				if(s[2]-t[2]==1||t[2]-s[2]==1) ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
} 
