#include<bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
char i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		i=c[2],j=d[2];
		if(c[0]==d[0]&&d[1]==c[1]){
			cout<<1;
			if(((i=='A'||i=='B'||i=='C')&&(j=='A'||j=='B'||j=='C'))||((i=='D'||i=='F')&&(j=='D'||j=='F'))){
				cout<<1;
				if((i=='A'&&j=='B')||(j=='A'&&i=='B')||(i=='B'&&j=='C')||(i=='C'&&j=='B')||(i=='D'&&j=='F')||((i=='F'&&j=='D'))){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		} else cout<<0<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0;
}
