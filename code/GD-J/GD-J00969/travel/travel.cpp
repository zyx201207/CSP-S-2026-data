#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string xrc,xrs,xxc,xxs;
	cin>>xrc>>xrs>>xxc>>xxs;
	bool a=0,b=0,c=0,d=0;
	set<char>sty;
	set<char>ste;
	sty.insert('A');
	sty.insert('B');
	sty.insert('C');
	ste.insert('D');
	ste.insert('E');
	if(xrc==xxc){
		a=1;
		if(xrs[0]==xxs[0] && xrs[1]==xxs[1]){
			b=1;
			char p,q;
			p=xrs[2],q=xxs[2];
			if((sty.count(p) && sty.count(q)) || (ste.count(p) && ste.count(q))) c=1;
			if((p=='B' && q=='A') || (p=='B' && q=='C') || (p=='A' &&q=='B') || (p=='C' && q=='B') || (p=='D' && q=='F') || (p=='F' && q=='D')){
				d=1;
			}
		}
	}cout<<a<<b<<c<<d;
	return 0;
}
