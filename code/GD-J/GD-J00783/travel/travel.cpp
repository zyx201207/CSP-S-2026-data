#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string s1,c1,s2,c2,ans;
int check(string n,string s){
	if(n==s||n[2]-s[2]==1||s[2]-n[2]==1)return 0;
	else if((n[2]=='D'&&s[2]=='F')||(n[2]=='F'&&s[2]=='D')) return 0;
	else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=1;i<=4;i++){
		ans[i]='0';
	}
	if(c1==c2) {
		ans[1]='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]='1';
			if(s1[2]<='C'&&s1[2]>='A'&&s2[2]>='A'&&s2[2]<='C') {ans[3]='1';if(check(s1,s2)==0) ans[4]='1';}
			if(s1[2]<='F'&&s1[2]>='D'&&s2[2]>='D'&&s2[2]<='F') {ans[3]='1';if(check(s1,s2)==0) ans[4]='1';}
		}
	}
	
	
	
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
} 
