#include<bits/stdc++.h>
using namespace std;
int ac,bc,arow,brow;
char ax,bx;
string s,a;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	for(int i=0;i<3;i++){
	    cin>>a;
		s+=a;	
	}
	ac=(s[0]-'0')*10+(s[1]-'0');
	bc=(s[5]-'0')*10+(s[6]-'0');
	arow=(s[2]-'0')*10+(s[3]-'0');
	brow=(s[7]-'0')*10+(s[8]-'0');
	ax=s[4];
	bx=s[9];
	if(ax>bx)swap(ax,bx);
	if(ac==bc){
		cout<<1;
		if(arow==brow){
			cout<<1;
			if(bx<='C'||ax=='D'){
				cout<<1;
				if(ax=='D'||ax=='B'||bx=='B'){
					cout<<1;
				}else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
