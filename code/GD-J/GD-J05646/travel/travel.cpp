#include<bits/stdc++.h>
using namespace std;
string c,c2,s,s2;
int a,b,x,y;
char q,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>s>>c2>>s2;
	a=(c[0]-'0')*10+(c[1]-'0');
	b=(c2[0]-'0')*10+(c2[1]-'0');
	x=(s[0]-'0')*10+(s[1]-'0');
	y=(s2[0]-'0')*10+(s2[1]-'0');
	q=s[2];
	p=s2[2];
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(q<='C'&&p<='C'){
				cout<<1;
				if(abs((q-'A')-(p-'A'))==1) cout<<1;
				else cout<<0;
			}
			else if(q>='D'&&p>='D') cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
