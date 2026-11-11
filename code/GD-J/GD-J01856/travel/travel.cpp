#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(s[2]=='F') s[2]='E';
	if(ss[2]=='F') ss[2]='E';
	if(c==cc){
		if((s[0]-'0')*10+s[1]-'0'==(ss[0]-'0')*10+ss[1]-'0'){
			if(s[2]=='D'&&ss[2]=='E'||s[2]=='E'&&ss[2]=='D'||s[2]!='E'&&s[2]!='D'&&ss[2]!='E'&&ss[2]!='D'){
				if(abs(s[2]-ss[2])==1){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
			}
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<"0000"; 
	}
	return 0;
}
