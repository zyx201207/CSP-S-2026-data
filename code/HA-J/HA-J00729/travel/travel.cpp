#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	string rs,xs;
	cin>>rc>>rs>>xc>>xs;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	else if(rc==xc){
		cout<<"1";
		string a="",b="";
		a=rs[0]+rs[1];
		b=xs[0]+xs[1];
		if(a==b){
			cout<<"1";
		}
		else if(a!=b){
			cout<<"000";
			return 0;
		}
		if(rs[2]>='A'&&rs[2]<='C'&&xs[2]>='A'&&xs[2]<='C'){
			cout<<"1";
		}
		else if(rs[2]>='E'&&rs[2]<='F'&&xs[2]>='E'&&xs[2]<='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
		if(rs[2]-xs[2]==1||rs[2]-xs[2]==-1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	
	return 0;
}
