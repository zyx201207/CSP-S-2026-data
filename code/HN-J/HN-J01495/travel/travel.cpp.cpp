#include<bits/stdc++.h>
using namespace std;
int f;
string x,sx,y,sy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>sx>>y>>sy;
	for(int i=0;i<2;i++){
		if(x[i]!=y[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	f=0;
	for(int i=0;i<2;i++){
		if(sx[i]!=sy[i]){
			cout<<"000";
			return 0;;
		} 		
	}
	cout<<"1";
	if(sx[2]=='A'&&sy[2]<'D') cout<<"1";
	else if(sx[2]=='B'&&sy[2]<'D') cout<<"1";
	else if(sx[2]=='C'&&sy[2]<'D') cout<<"1";
	else if(sx[2]=='D'&&sy[2]=='F') cout<<"1";
	else if(sx[2]=='F'&&sy[2]<'D') cout<<"1";
	else if(sy[2]=='B'&&sx[2]<'D') cout<<"1";
	else if(sy[2]=='C'&&sx[2]<'D') cout<<"1";
	else if(sy[2]=='A'&&sx[2]<'D') cout<<"1";
	else if(sy[2]=='D'&&sx[2]=='F') cout<<"1";
	else if(sy[2]=='F'&&sx[2]<'D') cout<<"1";
	else cout<<"0";
	
	if(sx[2]=='A'&&sy[2]=='B') cout<<"1";
	else if(sx[2]=='B'&&sy[2]=='C') cout<<"1";
	else if(sx[2]=='D'&&sy[2]=='E') cout<<"1";
	else if(sy[2]=='B'&&sx[2]=='C') cout<<"1";
	else if(sy[2]=='D'&&sx[2]=='E') cout<<"1";
	else if(sy[2]=='A'&&sx[2]=='B') cout<<"1";
	else cout<<"0";
	return 0;
}

