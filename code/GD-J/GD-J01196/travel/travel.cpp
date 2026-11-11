#include<bits/stdc++.h>
using namespace std;
string Rc,Rs,Xc,Xs;
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>Rc>>Rs>>Xc>>Xs;
	if(Rc==Xc){
		cout<<"1";
		if(Rs[0]==Xs[0]&&Rs[1]==Xs[1]){
			cout<<"1";
			if(Rs[2]<='C'&&Xs[2]<='C'||Rs[2]=='D'&&Xs[2]=='F'||Rs[2]=='F'&&Xs[2]=='D'){
				cout<<"1";
				if(Rs[2]<='C'&&Xs[2]<='C'&&abs(int(Rs[2])-Xs[2])==1||Rs[2]=='D'&&Xs[2]=='F'||Rs[2]=='F'&&Xs[2]=='D')cout<<1;
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
