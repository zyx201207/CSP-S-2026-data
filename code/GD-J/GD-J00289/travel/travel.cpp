#include<bits/stdc++.h>
using namespace std;
bool tx,txp,txpd,xl;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		tx = 1;
		if(b[0]==d[0]&&b[1]==d[1]){
			txp=1;
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F'))){
				txpd = 1;
				if(b[2]-1==d[2]||b[2]+1==d[2]){
					xl = 1;
				}
			}
		}
	}
	cout<<tx<<txp<<txpd<<xl;
	return 0;
} 
