#include<bits/stdc++.h>
using namespace std;
int a,b;
char x[5],y[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	int ax=(x[0]-'0')*10+x[1]-'0';
	int by=(y[0]-'0')*10+y[1]-'0';
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(ax==by) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((x[2]>='A'&&x[2]<='C')&&(y[2]>='A'&&y[2]<='C')) cout<<1;
	else if((x[2]=='D'||x[2]=='F')&&(y[2]=='D'||y[2]=='F')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((x[2]=='A'&&y[2]=='B')||(x[2]=='B'&&y[2]=='C')||(x[2]=='B'&&y[2]=='A')||(x[2]=='C'&&y[2]=='B')) cout<<1;
	else cout<<0;
	return 0;
}
