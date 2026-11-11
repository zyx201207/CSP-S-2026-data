#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<'1';
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<'1';
			char x=b[2],y=d[2],z;
			if(b[2]>d[2]){
				z=d[2];
				y=x;
				x=z;
			}
			if(y=='D'||y=='F'){
				if(x=='D'||x=='F'){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else{
				if(x=='B'){
					cout<<"11";
					return 0;
				}
				else if(x=='A'&&y=='B'){
					cout<<"11";
					return 0;
				}
				else if(x=='B'&&y=='C'){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"10";
					return 0;
				}	
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
