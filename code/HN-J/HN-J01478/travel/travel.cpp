#include<bits/stdc++.h>
using namespace std;
string a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else cout<<" 0";
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else cout<<"0";
	if((b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')||(b[2]<='F'&&b[2]>='D'&&d[2]<='f'&&d[2]>='D')){
		cout<<"1";
		if(b[2]-d[2]==1||d[2]-b[2]==1){
			if(b[2]=='C'||d[2]=='F'&&d[2]=='C'||d[2]=='F'){
				cout<<'0';
			}else{
				cout<<'1';
			}
		}
	}else{
		cout<<"00";
	}
}
