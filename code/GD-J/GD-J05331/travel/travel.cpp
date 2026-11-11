#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
bool check1(int n,int m){
	return n==m;
}
bool check2(string s,string c){
	return ((s[0]-'0')*10+(s[1]-'0'))==((c[0]-'0')*10+(c[1]-'0'));
}
bool check3(string s,string c){
	return ((s[2]<='C'&&c[2]<='C')||(s[2]>'C'&&c[2]>'C'));
}
bool check4(string s,string c){
	return (char(s[2]+1)==c[2]||char(s[2]-1)==c[2]);
}
signed main(){
	fast;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string s,c;cin>>n>>s>>m>>c;
	if(check1(n,m))cout<<1;
	else cout<<0;
	if(check1(n,m)&&check2(s,c))cout<<1;
	else cout<<0;
	if(check1(n,m)&&check2(s,c)&&check3(s,c))cout<<1;
	else cout<<0;
	if(check1(n,m)&&check2(s,c)&&check3(s,c)&&check4(s,c))cout<<1;
	else cout<<0;
	return 0;
}
