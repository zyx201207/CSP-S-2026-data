#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt=0,cna=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		cna=1;
	}
	else{
		cout<<0;
	}
	if(cna==1){
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			cnt=1;
		}
		else{
			cout<<0;
		}
		if(cnt==1){
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='D'||d[2]=='F'){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			if(!(d[2]=='C'&&b[2]=='D')&&!(b[2]=='C'&&d[2]=='D')){
				if(abs(b[2]-d[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}
		else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
		}	
	return 0;
} 
