#include <bits/stdc++.h>
using namespace std;

string r1, r2, x1, x2;
bool f1, f2, f3, f4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
		f1 = 1;
	}
	else cout<<0;
	if((r2[0]==x2[0])&&(r2[1]==x2[1])&&f1){
		cout<<1;
		f2=1;
	}
	else cout<<0;
	if(f2&&((r2[2]>='A'&&r2[2]<='C')&&(x2[2]>='A'&&x2[2]<='C'))){
		cout<<1;
		f3=1;
	}else if((r2[2]=='D'&&x2[2]=='F')||(x2[2]=='D'&&r2[2]=='F')){
		cout<<1;
		f3 = 1;
	}else cout<<0;
	if(f3&&(((r2[2]-1)==x2[2])||((r2[2]+1)==x2[2]))&&(r2[2]!='C'&&x2[2]!='D')&&(r2[2]!='D'&&x2[2]!='C')){
		cout<<1;
	}else if((r2[2]=='D'&&x2[2]=='F')||(x2[2]=='D'&&r2[2]=='F')){
		cout<<1;
	}else cout<<0;
	return 0;
}
