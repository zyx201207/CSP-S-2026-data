#include<bits/stdc++.h>
using namespace std;
char sr,sx;
int cr,cx,r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>r>>sr>>cx>>x>>sx;
//	cout<<cr<<' '<<r<<' '<<sr<<' '<<cx<<' '<<x<<' '<<sx<<"\n";
	if(cr==cx){
		cout<<1;
		if(r==x){
			cout<<1;
			if((sr>'C'&&sx>'C')||(sr<='C'&&sx<='C')){
				cout<<1;
				if(abs(sr-sx)==1||sr=='D'&&sx=='F'||sr=='F'&&sx=='D'){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}

