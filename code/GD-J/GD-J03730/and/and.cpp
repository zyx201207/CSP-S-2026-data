#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if(b[2]=='A'){
				if(d[2]=='B'){
					cout<<11;
					return 0;
				}
				else if(d[2]=='C'){
					cout<<10;
					return 0;
				}
				cout<<00;
				return 0;
			}
			else if(b[2]=='B'){
				if(d[2]=='D'||d[2]=='F'){
					cout<<"00";
					return 0;
				}
				else{
					cout<<11;
					return 0;
				}
			}
			else if(b[2]=='C'){
				if(d[2]=='B'){
					cout<<11;
					return 0;
				}
				else if(d[2]=='A'){
					cout<<10;
					return 0;
				}
				else if(d[2]=='D'||d[2]=='F'){
					cout<<"00";
					return 0;
				}
			}
			else{
				if(d[2]=='D'||d[2]=='F'){
					cout<<11;
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
		cout<<"000";
		return 0;
	}
	else{
		cout<<"0000";
		return 0;
	}
} 
