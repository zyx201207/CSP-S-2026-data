#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>x>>y;
	if(a==x){
		cout<<'1';
		if(b[0]==y[0] && b[1]==y[1]){
			cout<<'1';
			char i=b[2],j=y[2];
			if(i>j) swap(i,j);
			if((i<='C' && j<='C') || (i>'C' && j>'C')){
				cout<<'1';
				if((i=='A' && j=='B') || (i=='B' && j=='C') || (i=='D' && j=='F')){
					cout<<'1';
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	

	return 0;
}

