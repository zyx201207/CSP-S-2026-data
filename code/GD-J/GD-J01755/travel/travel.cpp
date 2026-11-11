#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a_,c_;
	string b_,d_;
	cin>>a_>>b_>>c_>>d_;
	if(a_==c_)cout<<1;
	else cout<<0;
	if(b_[1]==d_[1]&&b_[0]==d_[0]&&a_==c_)cout<<1;
	else cout<<0;
	if(b_[1]==d_[1]&&b_[0]==d_[0]&&a_==c_){
		if((b_[2]=='A'||b_[2]=='B'||b_[2]=='C')&&(d_[2]=='A'||d_[2]=='B'||d_[2]=='C'))cout<<1;
		else if((b_[2]=='D'||b_[2]=='F')&&(d_[2]=='D'||d_[2]=='F'))cout<<1;
		else cout<<0;
	}else cout<<0;
	if(b_[1]==d_[1]&&b_[0]==d_[0]&&a_==c_){
		if((b_[2]=='A'||b_[2]=='B'||b_[2]=='C')&&(d_[2]=='A'||d_[2]=='B'||d_[2]=='C')){
			if((b_[2]=='A'&&d_[2]=='B')||(b_[2]=='B'&&d_[2]=='A')||(b_[2]=='B'&&d_[2]=='C')||(b_[2]=='C'&&d_[2]=='B'))cout<<1;
			else cout<<0;
		}
		else if((b_[2]=='D'||b_[2]=='F')&&(d_[2]=='D'||d_[2]=='F'))cout<<1;
		else cout<<0;
	}else cout<<0;
}
