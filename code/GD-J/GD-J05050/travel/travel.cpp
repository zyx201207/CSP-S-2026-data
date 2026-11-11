//travel
#include<bits/stdc++.h>
using namespace std;
string ax,aw,bx,bw;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>aw>>bx>>bw;
	if(ax==bx){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string ap=aw.substr(0,2);
	string bp=bw.substr(0,2);
//	cout<<ap<<' '<<bp;
	if(ap==bp){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(aw[2]>='A'&&aw[2]<='C'&&bw[2]>='A'&&bw[2]<='C'){
		cout<<1;
		if(aw[2]!='B'&&bw[2]!='B'){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if((aw[2]=='D'&&aw[2]=='F')&&(bw[2]=='D'&&bw[2]=='F')){
		cout<<1<<1;
	}else{
		cout<<0<<0;
	}
	return 0;
}
