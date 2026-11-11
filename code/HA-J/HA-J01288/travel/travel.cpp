#include<bits/stdc++.h>
using namespace std;
string s,ss,c,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>c>>cc;
	if(s==c){
		if(ss[0]==cc[0]&&ss[1]==cc[1]){
			bool b=0,bb=0;
			if(ss[2]=='D'||ss[2]=='F')b=1;
			else b=0;
			if(cc[2]=='D'||cc[2]=='F')bb=1;
			else bb=0;
			if(b==bb){
				if(b) cout<<"1111";
				else if(ss[2]!='B'&&cc[2]!='B') cout<<"1110";
				else cout<<"1111";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
