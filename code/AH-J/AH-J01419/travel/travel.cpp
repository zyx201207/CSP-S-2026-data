#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2,sam="0",sam1="0";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	char x,x1;
	bool ok=1;
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		cout<<1;
	}else{
		cout<<0;
		ok=false;
	}
	for(int i=0;i<s.size();i++){
		if(i<s.size()-1){
			sam+=s[i];
			sam1+=s2[i];	
		}
		else {
			x=s[i];
			x1=s2[i];
		}
	}
	if(sam==sam1&&ok!=false){
		cout<<1;
	}else{
		cout<<0;
		ok=false;
	}
	if(x>='A'&&x<='C'&&x1>='A'&&x1<='C'&&ok!=false||x>='D'&&x<='F'&&x1>='D'&&x1<='F'&&ok!=false){
		cout<<1;
	}else {
		cout<<0;
		ok=false;
	}
	if(x-1==x1&&ok!=false||x1-1==x&&ok!=false){
		cout<<1;
	}else {
		cout<<0;
	}
	
	return 0;
 } 
