#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool dfs(char x){
	if(x=='A') return 0;
	else if(x=='B') return 0;
	else if(x=='C') return 0;
	else if(x=='D') return 1;
	else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<"1";
			if(dfs(b[2])==dfs(d[2])){
				cout<<"1";
				if(abs(b[2]-d[2])==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
