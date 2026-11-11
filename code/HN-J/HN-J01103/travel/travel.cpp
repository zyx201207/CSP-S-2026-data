#include<bits/stdc++.h>
using namespace std;
string a,b,l,r;
int d[5]={0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>l>>r;
	if(a==l){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	int x=10*(b[0]-'A')+b[1]-'A',y=10*(r[0]-'A')+r[1]-'A';
	if(x==y){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(d[b[2]-'A']==d[r[2]-'A']){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]==r[2]+1||r[2]==b[2]+1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
//10:29 !!! I AK CSP-J ίχ OwO 
