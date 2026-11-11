#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
void solve(){
	if(c1!=c2){
		cout<<0<<0<<0<<0;return;
	}else cout<<1;
	char a=s1[0],b=s1[1];
	char c=s2[0],d=s2[1];
	if(a!=c || b!=d){
		cout<<0<<0<<0;return;
	}else cout<<1;
	a=s1[2];c=s2[2];
	if(s1[2]-'A'+1>3 && s2[2]-'A'+1<=3){
		cout<<0<<0;return;
	}else if(s1[2]-'A'+1<=3 && s2[2]-'A'+1>3){
		cout<<0<<0;return;
	}else cout<<1;
	if(abs(a-c)==1)cout<<1;
	else cout<<0;
	return;
}
int abs(int a){
	return a>0?a:-a;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	solve();
	
	
	return 0;
}
