#include <bits/stdc++.h>
using namespace std;
bool fun(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C')return 1;
		return 0;
	}else{
		if(b=='A'||b=='B'||b=='C')return 0;
		return 1;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<1;
		if(b[1]==y[1]&&b[0]==y[0]){
			cout<<1;
			if(fun(b[2],y[2])){
				cout<<1;
				if(abs(b[2]-y[2])==1)cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
