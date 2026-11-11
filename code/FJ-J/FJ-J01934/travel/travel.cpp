#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int r,x;
	string rs,xs;
	cin>>r>>rs>>x>>xs;
	if(r==x){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((rs[2]>='A'&&rs[2]<='C')&&(xs[2]>='A'&&xs[2]<='C')){
		cout<<1;
	}else if((rs[2]>='D'&&rs[2]<='F')&&(xs[2]>='D'&&xs[2]<='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((rs[2]=='A'&&xs[2]=='B')){
		cout<<1;
		return 0;
	}else if((rs[2]=='B'&&xs[2]=='A')){
		cout<<1;
		return 0;
	}else if((rs[2]=='B'&&xs[2]=='C')){
		cout<<1;
		return 0;
	}else if((rs[2]=='C'&&xs[2]=='B')){
		cout<<1;
		return 0;
	}else if((rs[2]=='D'&&xs[2]=='F')){
		cout<<1;
		return 0;
	}else if((rs[2]=='F'&&xs[2]=='D')){
		cout<<1;
		return 0;
    }else{
    	cout<<0;
    	return 0;
	}   
	return 0;
}
