#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,n,m;
string c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	x=10*(c[0]-'0')+c[1]-'0';
	y=10*(d[0]-'0')+d[1]-'0';
	n=c[2]-'A';
	m=d[2]-'A';
	if(a==b){
		cout<<"1";
		if(x==y){
			cout<<"1";
			if((n<3&&m<3)||(n>3&&m>3)){
				cout<<"1";
				if(n==m+1||m==n+1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
