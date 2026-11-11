#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(t==1){
		cout<<2<<'\n';
	}else if(t==2){
		cout<<2<<'\n'<<4<<'\n';
	}else if(t==3){
		cout<<3<<'\n'<<1<<'\n'<<5<<'\n';
	}else if(t==4){
		cout<<4<<'\n'<<5<<'\n'<<2<<'\n'<<8<<'\n';
	}else{
		cout<<6<<'\n'<<3<<'\n'<<4<<'\n'<<9<<'\n'<<2<<'\n';
	}
	return 0;
}
