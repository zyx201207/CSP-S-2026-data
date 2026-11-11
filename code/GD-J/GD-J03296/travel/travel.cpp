#include<bits/stdc++.h>
#define int long long
using namespace std;
string rc,rs,xc,xs;
bool k=false;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>rc>>rs>>xc>>xs;
	
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		k=true;
	}
	if(k&&(rs[2]==xs[2])){
		cout<<"0000";
		return 0;
	}
	
	
	if(rc==xc){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		k=true;
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(k&&((rs[2]<='C'&&xs[2]<='C')||(rs[2]>='D'&&xs[2]>='D'))){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	if(k&&((rs[2]=='C'&&xs[2]=='D')||(rs[2]=='D'&&xs[2]=='C'))){
		cout<<"0";
		return 0;
	}
	
	int x=rs[2],y=xs[2];
	if(k&&(abs(x-y)==1)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

