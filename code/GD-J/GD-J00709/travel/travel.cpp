#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]=='0')x=a[1]-'0';
	else x=10+a[1]-'0';
	if(c[0]=='0')y=c[1]-'0';
	else y=10+c[1]-'0';
	if(x==y){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			if(b[2]=='F'||b[2]=='D'){
				if(d[2]=='F'||d[2]=='D'){
					cout<<"11";
				}
				else cout<<"00";
			}
			else{
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
					cout<<'1';
					if((d[2]-1)==b[2]||(d[2]+1)==b[2]){
						cout<<'1';
					}
					else cout<<'0';
				}
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
