#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	bool ok1=0,ok2=0,ok3=0,ok4=0;
	string r1_,r2_,x1_,x2_;
	cin>>r1_>>r2_>>x1_>>x2_;
	
	if(r1_==x1_)cout<<"1",ok1=1;
	else cout<<"0";
	
	if(ok1 && r2_[0]==x2_[0] && r2_[1]==x2_[1])cout<<"1",ok2=1;
	else cout<<"0";
	
	char x=r2_[2],y=x2_[2];
	if(ok1 && ok2){
		if(x=='D' || x=='F'){
			if(y=='D' || y=='F'){
				ok3=1; 
			}
		}
		else if(y=='A' || y=='B' || y=='C'){
			ok3=1;
		}
	}
	if(ok3)cout<<"1";
	else cout<<"0";
	
	if(ok1 && ok2 && ok3){
		if(x=='A' && y=='B')ok4=1;
		if(x=='B' && y=='A')ok4=1;
		if(x=='B' && y=='C')ok4=1;
		if(x=='C' && y=='B')ok4=1;
		if(x=='D' && y=='F')ok4=1;
		if(x=='F' && y=='D')ok4=1;
	}
	if(ok4)cout<<"1";
	else cout<<"0";
	return 0;
}
