//马辰一帆 GZ-J00578 贵阳市第三实验中学
#include<bits/stdc++.h>
using namespace std;
int a,b,paia,paib,g;
char liea,lieb;
bool ba,bb,bp;
string stra,strb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>stra>>b>>strb;
	bp=(a==b);
	if(bp) cout<<1;
	else cout<<0;
	paia=stra[0]*10+stra[1];
	paib=strb[0]*10+strb[1];
	if((paia==paib)&&bp) cout<<1;
	else cout<<0;
	liea=stra[2],lieb=strb[2];
	ba=(liea<='C'&&lieb<='C');
	bb=(liea>'C'&&lieb>'C');
	if(ba||bb&&(paia==paib)&&bp) cout<<1;
	else cout<<0;
	if(bb&&(paia==paib)&&bp) cout<<1;
	else cout<<0;
	return 0;
}
//hymmyyds 
