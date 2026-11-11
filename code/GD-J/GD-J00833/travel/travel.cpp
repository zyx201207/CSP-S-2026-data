#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int x=c[0]-'0';
	x*=10;
	x+=c[1]-'0';
	int y=d[0]-'0';
	y*=10;
	y+=d[1]-'0';
	char k1=c[2];
	char k2=d[2];
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if((k1=='D'||k1=='F')&&(k2=='D'||k2=='F')){
				cout<<"11";
			}else if((k1=='D'||k1=='F')||(k2=='D'||k2=='F')){
				cout<<"00";
			}else{
				cout<<1;
				int kk1=k1;
				int kk2=k2;
				if(abs(kk1-kk2)==1)cout<<1;
				else cout<<0;
			}
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
}
