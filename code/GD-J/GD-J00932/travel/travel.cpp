#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cx,bx,cy,by;
char xx,yy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>bx>>xx>>cy>>by>>yy;
	if(cx==cy){
		cout<<"1";
		if(bx==by){
			cout<<"1";
			if(xx=='A'){
				cout<<((yy=='B' || yy=='C')?"1":"0");
				cout<<((yy=='B')?"1":"0");
			}
			if(xx=='B'){
				cout<<((yy=='A' || yy=='C')?"1":"0");
				cout<<((yy=='A' || yy=='C')?"1":"0");
			}
			if(xx=='C'){
				cout<<((yy=='B' || yy=='A')?"1":"0");
				cout<<((yy=='B')?"1":"0");
			}
			if(xx=='D'){
				cout<<((yy=='E')?"1":"0");
				cout<<((yy=='E')?"1":"0");
			}
			if(xx=='E'){
				cout<<((yy=='D')?"1":"0");
				cout<<((yy=='D')?"1":"0");
			}
		}else cout<<"000";
		
		
	}else{
		cout<<"0000";
	}
} 
