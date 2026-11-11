#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b,x,y;
	cin>>a>>x>>b>>y;
	int zw=((int)x[0]-'0')*10+((int)x[1]-'0'),cw=(y[0]-'0')*10+(y[1]-'0');
	char xx=x[2],yy=y[2];
	if(a!=b){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	if(zw==cw){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((xx>='D')&&(yy>='D'))||(((xx<'D')&&(yy<'D')))){
		cout<<1;
		if(abs(xx-yy)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0<<0;
	}
	return 0;
}
