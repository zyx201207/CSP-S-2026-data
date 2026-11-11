#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string cx,cr,sx,sr;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		a=1;
	}
	if(a&&sr[0]+sr[1]==sx[0]+sx[1]){
		b=1;
	}
	if(a&&b){
		if((sr[2]=='F'&&sx[2]=='D')||(sr[2]=='F'&&sx[2]=='D')){
			c=1;
		}
		else if(sr[2]>='A'&&sr[2]<='C'&&sx[2]>='A'&&sx[2]<='C'){
			c=1;
		}
	}
	if(a&&b&&c){
		if((sr[2]=='F'&&sx[2]=='D')||(sx[2]=='F'&&sr[2]=='D')){
			d=1;
		}
		else if((sx[2]=='C'&&sr[2]=='B')||(sr[2]=='C'&&sx[2]=='B')){
			d=1;
		}
		else if((sx[2]=='A'&&sr[2]=='B')||(sr[2]=='A'&&sx[2]=='B')){
			d=1;
		}
	}
	cout<<a<<b<<c<<d<<'\n';
	return 0;
} 
