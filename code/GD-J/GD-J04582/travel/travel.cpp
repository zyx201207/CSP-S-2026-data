#include <bits/stdc++.h>
using namespace std;
string n,m,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<1;
		if(m[0]==y[0] && m[1]==y[1]){
			cout<<1;
			if(m[2]=='A' || m[2]=='B' || m[2]=='C' && y[2]=='A' || y[2]=='B' || y[2]=='C'){
				cout<<1;
				if(m[2]=='A' && y[2]=='B' || m[2]=='B' && y[2]=='C' || m[2]=='D' && m[2]=='F'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(m[2]=='D' || m[2]=='F' && y[2]=='D' || y[2]=='F'){
				cout<<1;
				if(m[2]=='A' && y[2]=='B' || m[2]=='B' && y[2]=='C' || m[2]=='D' && m[2]=='F'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}

	
	
	return 0;
}
