#include<bits/stdc++.h>
using namespace std;
int cr,cx;//r,x的车厢号
int sr,sx;//排号
char r,x;//座号 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>r>>cx>>sx>>x;
	if(cr!=cx){
		cout<<"0000";
		return 0;
		//车厢号都不一样 
	} 
	if(sr!=sx){
		cout<<"1000";
		return 0;
		//排号都不一样 
	}
	if((r=='C'||r=='A'||r=='B')&&(x=='D'||x=='F')){
		cout<<"1100";
		return 0; 
	}
	if((x=='C'||x=='A'||x=='B')&&(r=='D'||r=='F')){
		cout<<"1100";
		return 0; 
	}
	if((x=='C'&&r=='A')||(r=='C'&&x=='A')){
		cout<<"1110";
		return 0; 
	}
	cout<<"1111";
	return 0;
}
