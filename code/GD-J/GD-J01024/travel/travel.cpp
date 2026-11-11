#include<bits/stdc++.h>
using namespace std;
#define int long long
string cx,sx,cy,sy;
bool fa,fb,fc,fd;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx[0]==cy[0]&&cx[1]==cy[1]) fa=1;
	if(fa&&sx[0]==sy[0]&&sx[1]==sy[1]) fb=1;
	if(fb){
		switch(sx[2]){
			case 'A':if(sy[2]=='B'||sy[2]=='C') fc=1;break;
			case 'B':if(sy[2]=='A'||sy[2]=='C') fc=1;break;
			case 'C':if(sy[2]=='A'||sy[2]=='B') fc=1;break;
			case 'D':if(sy[2]=='F') fc=1;break;
			case 'F':if(sy[2]=='D') fc=1;break;
		}
	}
	if(fc){
		switch(sx[2]){
			case 'A':if(sy[2]=='B') fd=1;break;
			case 'B':if(sy[2]=='A'||sy[2]=='C') fd=1;break;
			case 'C':if(sy[2]=='B') fd=1;break;
			case 'D':if(sy[2]=='F') fd=1;break;
			case 'F':if(sy[2]=='D') fd=1;break;
		}
	}
	cout<<fa<<fb<<fc<<fd;
	return 0;
}

