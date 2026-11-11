#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
struct sit{
	int c;
	int s;
	char l;
	bool f;
};
sit x,r;
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	x.f=0;
	r.f=0;
	cin>>r.c>>r.s>>r.l>>x.c>>x.s>>x.l;
	//printf("%d\t%d %c\n%d\t%d %c",r.c,r.s,r.l,x.c,x.s,x.l);
	if(r.l=='A'||'B'||'C') r.f=1;
	else r.f=0;
	if(x.l=='D'||'F') x.f=0;
	else x.f=1;
	if(r.c==x.c){
		putchar('1');
		if(r.s==x.s){
			putchar('1');
			if(r.f==x.f){
				putchar('1');
				if(abs(r.l-x.l)==1) putchar('1');
				else cout<<0;
			}else puts("00");
		}else puts("000");
	}else puts("0000");
	
	return 0;
}
