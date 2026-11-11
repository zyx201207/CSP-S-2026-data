#include<bits/stdc++.h>
#define int long long
using namespace std;

string a,b,c,d;

bool aa,bb,cc,dd;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		aa=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			bb=1;
			if((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&b[2]=='D')){
				cc=1;
				if(b[2]=='A'){
					if(d[2]=='B'){
						dd=1;
					}
				}else if(b[2]=='B'){
					if(d[2]=='A'||d[2]=='C'){
						dd=1;
					}
				}else if(b[2]=='C'){
					if(d[2]=='B'){
						dd=1;
					}
				}else if(b[2]=='D'){
					if(d[2]=='F'){
						dd=1;
					}
				}else if(b[2]=='F'){
					if(d[2]=='D'){
						dd=1;
					}
				}
			}
		}
	}
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
