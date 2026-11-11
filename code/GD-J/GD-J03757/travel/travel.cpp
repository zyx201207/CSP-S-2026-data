#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int ch(char c){
	if(c=='A'||c=='B'||c=='C')return 1;
	else return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>cx>>sr>>sx;
	if(sr[2]=='F')sr[2]='E';
	if(sx[2]=='F')sr[2]='E';
	if(cr==sr)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(cx[1]==sx[1]&&cx[0]==sx[0])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(ch(cx[2])==ch(sx[2]))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(cx[2]-sx[2])==1)cout<<1;
	else cout<<0;
	return 0;
} 
