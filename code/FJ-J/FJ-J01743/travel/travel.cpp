#include<bits/stdc++.h>
using namespace std;
char aa[5],ab[5],ba[5],bb[5];
bool fg=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa>>ab>>ba>>bb;
	if(aa[1]==ba[1]&&aa[0]==ba[0]&&fg){
		cout<<1;
	}else{
		cout<<0;
		fg=false;
	} 
	if(ab[0]==bb[0]&&ab[1]==bb[1]&&fg) {
		cout<<1;
	}else{
		cout<<0;
		fg=false;
	}
	if(((ab[2]=='A'&&bb[2]=='B')||(ab[2]=='B'&&bb[2]=='A')||(ab[2]=='B'&&bb[2]=='C')||(ab[2]=='C'&&bb[2]=='B')||(ab[2]=='D'&&bb[2]=='F')||(ab[2]=='F'&&bb[2]=='D'))&&fg){
		cout<<11;
	}else if(((ab[2]=='A'&&bb[2]=='C')||(ab[2]=='C'&&bb[2]=='A'))&&fg){
		cout<<10;
	}else{
		cout<<0<<0;
	}
	return 0;
}
