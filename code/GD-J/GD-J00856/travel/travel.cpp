#include<bits/stdc++.h>
using namespace std;
string tr,sr,tx,sx;
bool j=false,p=false,c=false; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>tr>>sr>>tx>>sx;
	if(sr[2]=='F') sr[2]='E';
	if(sx[2]=='F') sx[2]='E';
	
	if(tr==tx){
		cout<<1;
		j=true;
	}
	else{
		cout<<0;
	}
	
	if(sr[0]==sx[0]&&sr[1]==sx[1]&&j){
		cout<<1;
		p=true;
	}
	else{
		cout<<0;
	}
	
	if(((sr[2]<='C'&&sx[2]<='C')||(sr[2]>='D'&&sx[2]>='D'))&&j&&p){
		cout<<1;
		c=true;
	}
	else{
		cout<<0;
	}
		
	if(abs(sr[2]-sx[2])==1&&j&&p&&c) cout<<1;
	else cout<<0;
	return 0;
}
