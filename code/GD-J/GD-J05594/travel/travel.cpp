#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string rc,rs,xc,xs;
	cin>>rc>>rs>>xc>>xs;
	int r=rs[2],x=xs[2];
	int irc=rc[0]+rc[1];
	int ixc=xc[0]+xc[1];
	if(irc!=ixc){
		cout<<"0000";
		return 0;
	}
	else if(rs[0]!=xs[0]||rs[1]!=xs[1]){
		cout<<1000;
		return 0;
	}
	else if(rs[2]-'A'<3&&xs[2]-'A'>=3||xs[2]-'A'<3&&rs[2]-'A'>=3){
		cout<<1100;
		return 0;
	}
	else if(r>x&&r-x!=1||x>r&&x-r!=1){
		cout<<1110;
		return 0;
	}
	else{
		cout<<1111;
	}
	
	return 0;
} 
