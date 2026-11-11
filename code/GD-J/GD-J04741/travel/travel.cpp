#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		if(b[0]==d[0]&&b[1]==d[1]){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					if(b[2]=='A'&&d[2]=='B')puts("1111");
					else if(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))puts("1111");
					else if(b[2]=='C'&&d[2]=='B')puts("1111");
					else puts("1110");
				}
				else puts("1100");
			}
			else{
				if(d[2]=='D'||d[2]=='F'){
					if(b[2]=='D'&&d[2]=='F')puts("1111");
					else if(b[2]=='F'&&d[2]=='D')puts("1111");
					else puts("1110");
				}
				else puts("1100");
			}
		}
		else puts("1000");
	}
	else puts("0000");
	return 0;
}
