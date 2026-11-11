#include<bits/stdc++.h>
#define int long long
using namespace std;
int cx,cs,xx,xs;
char c,x;
bool pai=0,ce=0,xiang=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld%c %lld %lld%c",&cx,&cs,&c,&xx,&xs,&x);
	if(cx==xx){cout<<1;xiang=1;}
	else {cout<<0;xiang=0;}
	
	if(xiang&&(cs==xs)){cout<<1;pai=1;}
	else {cout<<0;pai=0;}
	
	if(xiang==0||pai==0)cout<<0;
	else{
		if((c>='A'&&c<='C'&&x>='A'&&x<='C')||(c>='D'&&c<='F'&&x>='D'&&x<='F')){
			cout<<1;
			ce=1;
		}
		else{
			cout<<0;
			ce=0;
		}
	}
	
	if(xiang&&ce&&pai){
		if((c=='A'&&x=='B')||(c=='B'&&(x=='A'||x=='C'))||(c=='C'&&x=='B')||(c=='D'&&x=='F'||(c=='F'&&x=='D'))){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
