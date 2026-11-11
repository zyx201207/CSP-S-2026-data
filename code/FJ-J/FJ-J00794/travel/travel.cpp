#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,ah,bx,bh;
	cin>>ax>>ah>>bx>>bh;
	if(ax!=bx){
		cout<<0<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	int aj=(ah[0]-'0')*10+(ah[1]-'0');
	int bj=(bh[0]-'0')*10+(bh[1]-'0');
	//cout<<aj<<bj;
	if(aj==bj){
		cout<<1;
		if((ah[2]<='C'&&bh[2]<='C')||(ah[2]>='D'&&ah[2]>='D')){
			cout<<1;
			if(abs(ah[2]-bh[2])<=1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0<<0;
		}
	}else{
		cout<<0<<0<<0;
	}
	
	return 0;
}
