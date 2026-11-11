#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(b[2]=='F')b[2]='E';
	if(d[2]=='F')d[2]='E';
	if(a!=c){
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(a==c)cout<<1;
	else cout<<0;
	string ph=b.substr(0,2),ph1=d.substr(0,2);
	if(ph==ph1)cout<<1;
	else cout<<0;
	if(ph==ph1&&(!((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')))){
		cout<<1;
	} 
	else cout<<0;
	if(ph==ph1&&abs(b[2]-d[2])==1&&(!((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')))){
		cout<<1;
	}
	else cout<<0;
	
	return 0;
} 
