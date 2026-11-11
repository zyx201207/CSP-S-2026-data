#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int maxn=2e6+5;
const int mod=1e9+7;
int a[maxn];
char ac[10]={'A','B','C',' ','D','F'};
int check(char c){
	int i=-1;
	while(ac[++i]!=c)continue;
	return i;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,u,v;
	cin>>s>>t>>u>>v;
	if(s==u)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(t[0]==u[0]||t[1]==u[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((t[2]=='A'||t[2]=='B'||t[2]=='C')&&(v[2]=='D'||v[2]=='F')||(v[2]=='A'||v[2]=='B'||v[2]=='C')&&(t[2]=='D'||t[2]=='F')){
		cout<<'00';
		return 0;
	}
	else cout<<1;
	if(abs(check(t[2])-check(v[2]))<=1)cout<<1;
	else cout<<0;
	return 0;
}
