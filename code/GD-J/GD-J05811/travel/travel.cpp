#include<bits/stdc++.h>
using namespace std;
string b,d;
int a,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[1]==d[1]&&b[0]==d[0]){
			cout<<"1";
			if((b[2]=='A'||b[2]=='B'||b[2]||'C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
				cout<<"1";
				int x=b[2]-d[2];
				if(x==1||x==-1){
					cout<<"1";
				}else cout<<"0";
			}else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				cout<<"11";
			}else cout<<"00"; 
		}
		else cout<<"000";
	}else cout<<"0000";
	
	return 0;
} 
