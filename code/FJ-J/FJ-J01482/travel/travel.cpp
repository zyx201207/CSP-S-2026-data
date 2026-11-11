#include<bits/stdc++.h>
using namespace std;
int a,x;
string b,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a!=x) cout<<"0000";
	else{
		cout<<"1";
		if(b[0]!=y[0]||b[1]!=y[1]) cout<<"000";
		else{
			cout<<"1";
			if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(y[2]=='D'||y[2]=='F')){
				cout<<"00";
			}
			else if((y[2]=='A'||y[2]=='B'||y[2]=='C')&&(b[2]=='D'||b[2]=='F')){
				cout<<"00";
			}
			else{
				cout<<"1";
				if(abs(int(y[2])-int(b[2]))==1||(b[2]=='D'&&y[2]=='F')||(y[2]=='F'&&b[2]=='D')){
					cout<<"1";
				} 
				else cout<<"0";
			}
		}
	}
	return 0;
} 
