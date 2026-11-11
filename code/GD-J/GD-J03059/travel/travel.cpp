#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,d;
	int a,c;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			char c1=b[2],c2=d[2];
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
				cout<<11;
			}
			else if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')){
				cout<<1;
				if((c1=='A'||c1=='B')&&c2==c1+1){
					cout<<1; 
				}
				else if((c2=='A'||c2=='B')&&c1==c2+1){
					cout<<1;
				}
				else{
					cout<<0;
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
