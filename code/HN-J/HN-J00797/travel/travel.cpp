#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
string a,x,y,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	ll xl=x[0]+x[1];
	ll yl=y[0]+y[1];
	if(a!=b){
		cout<<"0000";
		return 0;
	}else cout<<1;
	if(xl==yl)cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	char xr=x[2],yr=y[2];
	ll up=0;
	if(xr=='D'||xr=='F'){
		up++;
	}
	if(yr=='D'||yr=='F'){
		up++;
	}
	if(up==2||up==0)cout<<1;
	else{
		cout<<"00";
		return 0; 
	}
	ll xc=x[2]-'A',yc=y[2]-'A';
	if(xc+1==yc||yc+1==xc)cout<<1;
	else cout<<0;
	return 0;
}
