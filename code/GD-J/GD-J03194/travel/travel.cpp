#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	n=false;m=false;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<1;
			n=true;
		}
		else cout<<0;
		if(n&&(b[2]=='A'||b[2]=='B'||b[2]=='C')){
			if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				cout<<1;
				m=true;
			}else cout<<0;
		}else{
			if(d[2]=='D'||d[2]=='E'){
				cout<<1;
				m=true;
			}else cout<<0;
		}
		if(n&&m&&abs(d[2]-b[2])==1)cout<<1;
		else cout<<0;
	}
	else cout<<"0000";
	return 0;
} 
