#include<bits/stdc++.h>
using namespace std;

string s1,s2,t1,t2;
bool f=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	cin>>s1>>t1>>s2>>t2;
	
	if(s1==s2) cout<<1;
	else{
		cout<<0;
		f=false;	
	}
	
	
	int k1=t1[0]-'0'*10+t1[1]-'0';
	int k2=t2[0]-'0'*10+t2[1]-'0';	
	if(!f) cout<<0;
	else if(k1==k2) cout<<1;
	else{
		cout<<0;
		f=false;	
	}
	
	char e1=t1[2],e2=t2[2];
	if(!f) cout<<0;
	else if((e1=='A'||e1=='B'||e1=='C')&&(e2=='A'||e2=='B'||e2=='C')) cout<<1;
	else if((e1=='D'||e1=='F')&&(e2=='D'||e2=='F')) cout<<1;
	else{
		cout<<0;
		f=false;
	}
	
	if(!f) cout<<0;
	else {
		if((e1=='B'&&(e2>='A'||e2<='C'))||(e2=='B'&&(e1>='A'||e1<='C'))) cout<<1;
		else if((e1=='D'||e1=='F')&&(e2=='D'||e2=='F')) cout<<1;
		else cout<<0;
	}
	
	return 0;
}
