#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b,c,d;
int w,x,y,z;
char i,j;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	w=(a[0]-'0')*10+(a[1]-'0');
	y=(c[0]-'0')*10+(c[1]-'0');
	x=(b[0]-'0')*10+(b[1]-'0');
	z=(d[0]-'0')*10+(d[1]-'0');
	i=b[2];
	j=d[2];
	if(w==y){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(x==z){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((i=='A'||i=='B'||i=='C')&&(j=='A'||j=='B'||j=='C'))||((i=='D'||i=='F')&&(j=='D'||j=='F'))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(i-j)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
