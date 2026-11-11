#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&f==1){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(f==1&&(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='E')&&(b[2]=='D'||b[2]=='E')))){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
		f=0;
	}
	if((int(b[2])+1==int(d[2])||int(d[2])+1==int(b[2]))&&f==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
