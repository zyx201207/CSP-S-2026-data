#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ss_,s_,ss,s;
	cin>>ss_>>s_>>ss>>s;
	if(ss_==ss){
		cout<<1;
		if(s_[0]==s[0]&&s_[1]==s[1]){
			cout<<1;
			if(s_[2]=='A'||s_[2]=='B'||s_[2]=='C'){
				if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
					cout<<1;
					if(s_[2]-s[2]==1||s[2]-s_[2]==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<0<<0;
				}
			}else{
				if(s[2]=='D'||s[2]=='F'){
					cout<<11;
				}else{
					cout<<0<<0;
				}
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
}
