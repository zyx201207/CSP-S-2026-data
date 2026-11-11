#include<iostream>
#include<string.h>
using namespace std;
string rc,xc;
string rs,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<1;
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			cout<<1;
			if(rs[2]=='D'&&xs[2]=='F'){
				cout<<11;
				return 0;
			}
			else if(xs[2]=='D'&&rs[2]=='F'){
				cout<<11;
				return 0;
			}
			else if(xs[2]=='D'&&rs[2]=='A'){
				cout<<"00";
				return 0;
			}
			else if(xs[2]=='F'&&rs[2]=='A'){
				cout<<"00";
				return 0;
			}
			else if(xs[2]=='D'&&rs[2]=='B'){
				cout<<"00";
				return 0;
			}
			else if(xs[2]=='F'&&rs[2]=='B'){
				cout<<"00";
				return 0;
			}
			else if(xs[2]=='D'&&rs[2]=='C'){
				cout<<"00";
				return 0;
			}
			else if(xs[2]=='F'&&rs[2]=='C'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='D'&&xs[2]=='A'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='F'&&xs[2]=='A'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='D'&&xs[2]=='B'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='F'&&xs[2]=='B'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='D'&&xs[2]=='C'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='F'&&xs[2]=='C'){
				cout<<"00";
				return 0;
			}
			else if(rs[2]=='A'&&xs[2]=='C'){
				cout<<10;
				return 0;
			}
			else if(xs[2]=='A'&&rs[2]=='C'){
				cout<<10;
				return 0;
			}
			else{
				cout<<11;
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
}
