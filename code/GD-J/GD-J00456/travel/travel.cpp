#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";return 0;
	}
	cout<<"1";
	x=(b[0]-'0')*10+(b[1]-'0');
	y=(d[0]-'0')*10+(d[1]-'0');
	if(x!=y){
		cout<<"000";return 0;
	}
	cout<<"1";x=b[2]-'A';y=d[2]-'A';
	if(x==2&&y==3||x==3&&y==2){
		cout<<"00";return 0;
	}
	cout<<"1";
	if(x==y+1||y==x+1)cout<<"1";
	else cout<<"0";
	return 0;
}
