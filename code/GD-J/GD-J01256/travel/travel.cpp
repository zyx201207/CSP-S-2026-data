#include<bits/stdc++.h>
#include<iostream>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'&&b[2]!='E'&&d[2]!='E')){
				cout<<1;
				if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					cout<<1;
				}
				else{
					int x=b[2]-'A'+1,y=d[2]-'A'+1;
					if(x+1==y||x-1==y){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
