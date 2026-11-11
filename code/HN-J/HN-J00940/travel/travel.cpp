#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx,r[5],x[5],a=0,b=0,c=0;
	string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
		c=1;
	}
	else cout<<"0";
	for(int i=0;i<3;i++){
		r[i]=sr[i]-'0';
		x[i]=sx[i]-'0';
	}
	if(c==1&&r[0]==x[0]&&r[1]==x[1]){
		cout<<"1";
		a=1;
	}
	else cout<<"0";
	if(a==1&&(r[2]<=19&&x[2]<=19||r[1]>21&&x[1]>21)) cout<<"1";
	else{
		cout<<"0";
		b=1;
	}
	if(b!=1&&r[2]+1==x[2]) cout<<"1";
	else cout<<"0";
	return 0;
}
