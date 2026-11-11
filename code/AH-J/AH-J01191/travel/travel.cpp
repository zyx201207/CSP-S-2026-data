#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int rcar,xcar,rpai,xpai;
	string rseat,xseat,rhang,xhang;
	cin>>rcar>>rseat>>xcar>>xseat;
	if(rseat[0]=='0')rpai=rseat[1]-'0';
	else 	rpai+=(rseat[0]-'0')*10+rseat[1]-'0';
	if(xseat[0]=='0')xpai=xseat[1]-'0';
	else 	xpai+=(xseat[0]-'0')*10+xseat[1]-'0';
	xhang=xseat[2];
	rhang=rseat[2];
    if(rcar!=xcar){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else {
		cout<<1;
		if(rpai!=xpai)cout<<0<<0<<0;
		else {
		cout<<1;
		if(((xhang=="A"||xhang=="B"||xhang=="C")&&(rhang=="A"||rhang=="B"||rhang=="C"))||((xhang=="D"||xhang=="F")&&(rhang=="D"||rhang=="F")))
			{
				cout<<1;
				if((rhang=="D"&&xhang=="F")||(rhang=="F"&&xhang=="D")||(rhang=="A"&&xhang=="B")||(rhang=="B"&&xhang=="A")||(rhang=="c"&&xhang=="A")||(rhang=="A"&&xhang=="C")||(rhang=="B"&&xhang=="C")||(rhang=="C"&&xhang=="B"))
					cout<<1;
				else cout<<0;
			}
		else cout<<0<<0;
		}
	}
	return 0;
	}
