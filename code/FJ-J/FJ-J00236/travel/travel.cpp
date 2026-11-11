#include<bits/stdc++.h>
#define int long long
using namespace std;
int cr,cx,x,y;
string sr,sx;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	x=(sr[0]-'0')*10+(sr[1]-'0');
	y=(sx[0]-'0')*10+(sx[1]-'0');
	if(cr==cx){
		if(x==y){
			if(sr[2]=='A'){
				if(sx[2]=='D'||sx[2]=='F'){
					cout<<"1100";
					return 0;
				}
			}
			if(sr[2]=='B'){
				if(sx[2]=='D'||sx[2]=='F'){
					cout<<"1100";
					return 0;
				}
			}
			if(sr[2]=='C'){
				if(sx[2]=='D'||sx[2]=='F'){
					cout<<"1100";
					return 0;
				}
			}
			if(sr[2]=='D'){
				if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'){
					cout<<"1100";
					return 0;
				}
			}
			if(sr[2]=='F'){
				if(sx[2]=='A'||sx[2]=='B'||sx[2]=='C'){
					cout<<"1100";
					return 0;
				}
			}
			if(sr[2]=='D'){
				if(sx[2]!='F'){
					cout<<"1110";
					return 0;
				} 
			}
			if(sr[2]=='F'){
				if(sr[2]!='D'){
					cout<<"1110";
					return 0;
				}
			}
			int y=abs(signed(sr[2])-signed(sx[2]));
			if(y!=1){
				cout<<"1110";
				return 0;
			}else{
				cout<<"1111";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
