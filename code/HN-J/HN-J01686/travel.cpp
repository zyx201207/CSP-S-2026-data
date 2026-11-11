#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,c;
	int e=0,f=0,g=0,k=0;
	string b,d;
	cin >>a>>b>>c>>d;
	if(a==c){
		e=1;
		f=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				g=1;
				k=1;
			}
		}
		else if(b[2]=='D'||b[2]=='F'){
			if(d[2]=='D'||d[2]=='F'){
				g=1;
				k=1;
			}
		}
	}
	cout<<e<<f<<g<<k;
	return 0;
} 
