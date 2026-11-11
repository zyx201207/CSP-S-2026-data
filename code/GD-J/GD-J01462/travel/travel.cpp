#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	char q,w;
	cin>>a>>b>>c>>d;
	q=b[2];
	w=d[2];
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'))){
				cout<<1;
				if(q==w||(q=='A'&&w=='C')||(q=='C'&&w=='A'))cout<<0;
				else cout<<1;
			}else {
				cout<<"00";
				return 0;
			}
		}else {
			cout<<"000";
			return 0;
		}
		
	}else {
		cout<<"0000";
		return 0;
	}
	
	//if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='F'||b[2]=='D')&&(d[2]=='F'||d[2]=='D'||))&&())
	
	return 0;
} 
