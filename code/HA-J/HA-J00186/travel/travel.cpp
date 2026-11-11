#include <bits/stdc++.h>
using namespace std;
bool pai(char a,char b){
	if(a>b) swap(a,b);
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='D'&&b=='E') return 1;
	return 0;
}
bool ce(char a,char b){
	if(a>='A'&&a<='C'&&b>='A'&&b<='C') return 1;
	if(a>='D'&&a<='E'&&b>='D'&&b<='E') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int n1=(s1[0]-'0')*10+s1[1]-'0';
	int n2=(s2[0]-'0')*10+s2[1]-'0';
//	cout<<n1<<' '<<n2<<'\n';
	if(c1==c2) cout<<1;
	else{
		cout<<"0000\n";
		return 0;
	}
	if(n1==n2){
		cout<<1;
		if(ce(s1[2],s2[2])) cout<<1;
		else cout<<0;
	}
	else cout<<0<<0;
	
	if((n1==n2&&pai(s1[2],s2[2]))||((s1[2]==s2[2])&&abs(n1-n2)==1)){
		cout<<1;
	}
	else cout<<0;
	cout<<'\n';
	return 0;
}