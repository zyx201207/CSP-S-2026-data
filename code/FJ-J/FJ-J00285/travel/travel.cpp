#include<bits/stdc++.h>
using namespace std;
int cx,sx,cy,sy;
char x,y;
int e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>x>>cy>>sy>>y;
	if(cx==cy){
		cout<<1;
	} else{
		cout<<"0000";
		return 0;
	}if(sx==sy){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	e=x-'A';
	f=y-'A';
	if((e<3&&f<3)||(e>=3&&f>=3)) {
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if((e-f)==1||(f-e)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
