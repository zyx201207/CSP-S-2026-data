#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string xc,xs,yc,ys;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xc>>xs>>yc>>ys;
	
	ll x,y;
	if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C'){
		x=0;
	}else{
		x=1;
	}
	if(ys[2]=='A'||ys[2]=='B'||ys[2]=='C'){
		y=0;
	}else{
		y=1;
	}
	ll xx,yy;
	if(xs[2]=='A'){
		xx=1;
	}else if(xs[2]=='B'){
		xx=2;
	}else if(xs[2]=='C'){
		xx=3;
	}else if(xs[2]=='D'){
		xx=4;
	}else if(xs[2]=='F'){
		xx=5;
	}
	if(ys[2]=='A'){
		yy=1;
	}else if(ys[2]=='B'){
		yy=2;
	}else if(ys[2]=='C'){
		yy=3;
	}else if(ys[2]=='D'){
		yy=4;
	}else if(ys[2]=='F'){
		yy=5;
	}
	
	if(xc[0]==yc[0]&&xc[1]==yc[1]){//同一车厢
		cout<<1;
		if((xs[0]==ys[0])&&(xs[1]==ys[1])){//同一排
			cout<<1;
			ll f=1;
			if((xx==3&&yy==4)||(xx==4&&yy==3)){
				f=0;
			}else{
				f=1;
			}
			if(x==y){
				cout<<1;
				if(abs(xx-yy)==1&&f==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
