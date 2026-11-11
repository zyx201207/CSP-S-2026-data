#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string x,y,a1,b1;
	cin>>a1>>x>>b1>>y;
	a=(a1[0]-'0')*10+a1[1]-'0';
	b=(b1[0]-'0')*10+b1[1]-'0';
	int u,d;
	u=(x[0]-'0')*10+(x[1]-'0');
	d=(y[0]-'0')*10+(y[1]-'0');
	//cout<<u<<" "<<d<<endl;
	if(a==b){
		cout<<1;
		if(u==d){
			cout<<1;
			char h=x[2],v=y[2];
			if((h=='A'||h=='B'||h=='C')&&(v=='A'||v=='B'||v=='C')){
				cout<<1;
				if(h=='A'&&v=='B'||h=='B'&&v=='A'||h=='B'&&v=='C'||h=='C'&&v=='B')cout<<1;
				else cout<<0;
			}
			else if((h=='D'||h=='F')&&(v=='D'||v=='F')){
				cout<<1<<1;
				if(h=='A'&&v=='B'||h=='B'&&v=='A'||h=='B'&&v=='C'||h=='C'&&v=='B')cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;//daociyiyou
	return 0;
} 
