#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,c_;
	char s[3],s_[3];
	cin>>c>>s>>c_>>s_;
	if(c==c_){
		cout<<1;
		if(s[0]==s_[0]&&s[1]==s_[1]){
			cout<<1;
			if((s[2]=='A'&&(s_[2]=='B'||s_[2]=='C'))||
			(s[2]=='B'&&(s_[2]=='A'||s_[2]=='C'))||
			(s[2]=='C'&&(s_[2]=='A'||s_[2]=='B'))||
			(s[2]=='D'&&s_[2]=='E')||
			(s[2]=='E'&&s_[2]=='D')){
				cout<<1;
				if(s[2]-s_[2]==1||s[2]-s_[2]==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
} 
