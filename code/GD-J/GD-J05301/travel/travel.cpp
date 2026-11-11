#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000\n";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000\n";
		return 0;
	}
	int r=b[2],l=d[2];
	if ( (r=='D'||r=='E') && (l=='D'||l=='E') ){
		cout<<"11\n";
		return 0;
	}else if((r=='A'||r=='B'||r=='C')&&(l=='A'||l=='B'||l=='C')){
		cout<<1;
	}else{
		cout<<"00\n";
		return 0;
	}
	if((r=='A'&&l=='B')||(r=='B'&&l=='C')){
		cout<<"1\n";
	}else{
		cout<<"0\n";
	}
	return 0;
}
