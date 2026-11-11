#include<bits/stdc++.h>
using namespace std;
int a,az,b,bz;
char azc,bzc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>az>>azc>>b>>bz>>bzc;
	if(a==b){
		cout<<1;
		if(az==bz) cout<<1;
		else cout<<0;
		if(az==bz){
			if(int(azc)<='C'&&int(bzc)<='C'||int(azc)>='D'&&int(bzc)>='D'){
				cout<<1;
				if(abs(int(azc)-int(bzc))<=1||int(azc)>='D'&&int(bzc)>='D') cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"00";
	}else cout<<"0000";
	return 0;
} 
