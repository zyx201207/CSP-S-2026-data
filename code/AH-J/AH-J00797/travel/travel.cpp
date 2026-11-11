#include<bits/stdc++.h>
using namespace std;
string s,x,t,y;
int f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>x>>t>>y;
	if(s==t) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	string x1=x.substr(0,2),x2=x.substr(2,1);
	string y1=y.substr(0,2),y2=y.substr(2,1);
	if(x1==y1) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((x2>="A"&&x2<="C"&&y2>="A"&&y2<="C")||(x2>="D"&&x2<="F"&&y2>="D"&&y2<="F")){
		cout<<1;
		f=1;
	}else{
		cout<<0;
	}
	if(f){
		if((x2=="A"&&y2=="B")||(x2=="B"&&y2=="A")) cout<<1;
		else if((x2=="B"&&y2=="C")||(x2=="C"&&y2=="B")) cout<<1;
		else if((x2=="D"&&y2=="F")||(x2=="F"&&y2=="D")) cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
