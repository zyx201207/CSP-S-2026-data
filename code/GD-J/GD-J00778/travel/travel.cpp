#include<bits/stdc++.h>
using namespace std;
int cr,cx;
string r,x;
int rr,xx;
char rrr,xxx;
int main(){
	
//	ios::sync_with_stdio(false);
//	cin.tie(0);   cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>r>>cx>>x;
	rr=(r[0]-'0')*10+r[1]-'0';
	rrr=r[2];
	xx=(x[0]-'0')*10+x[1]-'0';
	xxx=x[2];
	if(cr==cx){
		cout<<1;
		if(rr==xx){
			cout<<1;
			if((rrr<='C'&&xxx<='C')||(rrr>='D'&&xxx>='D')){
				cout<<1;
				if(abs(rrr-xxx)==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";	
	}
} 
