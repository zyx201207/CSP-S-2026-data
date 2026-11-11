#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	bool k=false,x=false;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		x=true;
	}
	else{
		cout<<0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]&&x){
		cout<<1;
		k=true;
	}
	else{
		cout<<0;
	}
	if((((s[2]>='A'&&s[2]<='C')&&(ss[2]>='A'&&ss[2]<='C'))||((s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')))&&k&&x){
		cout<<1;
		int a=(int)s[2],b=(int)ss[2];
		if(max(a,b)-min(a,b)==1&&k){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0<<0;
	}
	return 0;
}

