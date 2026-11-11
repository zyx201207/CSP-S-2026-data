#include<bits/stdc++.h>
using namespace std;
//unsigned const struct  (vector pueue stack ) push pop empty / pow abs sqrt /reverse unqine
//scanf printf %.3f %lf %d
//fixed setpreicion
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool af=0,bf=0,cf=0,df=0;
	cin>>a>>b>>c>>d;
	af=(a==c);
	bf=(b[0]==d[0]&&b[1]==d[1]);
	cf = ((b[2]-'A'+1<=3&&d[2]-'A'+1<=3)||(b[2]-'A'+1>3&&d[2]-'A'+1>3));
	df = abs(b[2]-d[2])<=1;
	if(af){
		cout<<1;
	}else{
		cout<<0;
	}
	if(af&&bf){
		cout<<1;
	}else{
		cout<<0;
	}
	if(af&bf&cf){
		cout<<1;
	}else{
		cout<<0;
	}
	if(af&bf&cf&df){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
