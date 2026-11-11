#include<bits/stdc++.h>
using namespace std;
string c_,s_,c__,s__;
int ce(char c){
	if(c=='A'||c=='B'||c=='C') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_>>s_>>c__>>s__;
	if(c_!=c__) cout<<"0000";
	else{
		cout<<"1";
		if(s_[0]!=s__[0]||s_[1]!=s__[1]) cout<<"000";
		else{
			cout<<"1";
			char ch_=s_[2],ch__=s__[2];
			int num_=ce(ch_),num__=ce(ch__);
			if(num_!=num__) cout<<"00";
			else{
				cout<<"1";
				if(ch_=='A'&&ch__=='C'||ch_=='C'&&ch__=='A') cout<<"0";
				else cout<<"1";
			}
		}
	}
	return 0;
}
