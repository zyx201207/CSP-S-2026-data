#include<bits/stdc++.h>
using namespace std;
int ac,bc,ap,bp,i,j,k,l,h;
char t,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac;
	for(i=1;i<=2;i++){
		cin>>t;
		ap=ap*10+(t-'0');
	}
	cin>>a;
	
	cin>>bc;
	for(i=1;i<=2;i++){
		cin>>t;
		bp=bp*10+(t-'0');
	}
	cin>>b;
	
	bool cmp=false;
	
	if(ac==bc) cout<<1;
	else cout<<0;
	if(ac==bc&&ap==bp) cout<<1;
	else cout<<0;
	if(ac==bc&&ap==bp){
		if(int(a)-64<=3&&int(b)-64<=3){
			cout<<1;
			cmp=true;
		}
		else if(int(a)-64>3&&int(b)-64>3){
			cout<<1;
			cmp=true;
		}
		else cout<<0;
	}
	else cout<<0;
	if(cmp){
		if(abs(int(a)-int(b))==1&&!((a=='C'&&b=='D')||(a=='D'&&b=='C'))) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
