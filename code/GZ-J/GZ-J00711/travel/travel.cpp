//凯里市第一初级中学 刘泓毅 GZ-J00711
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char rs[3],xs[3];
	int rc,xc;
	cin>>rc>>rs>>xc>>xs;
	bool b1=0,b2=0,b3=0;
	if(rc==xc){
		b1=1;cout<<1;
	}else cout<<0;
	if(b1&&(rs[0]==xs[0]&&rs[1]==xs[1])){
		b2=1;cout<<1;
	}else cout<<0;
	if(b1&&b2&&(rs[2]<='C'&&xs[2]<='C'||rs[2]>='D'&&xs[2]>='D')){
		b3=1;cout<<1;
	}else cout<<0;
	if(b1&&b2&&b3&&(abs(rs[2]-xs[2])==1))cout<<1;
	else cout<<0;
	return 0;
}
