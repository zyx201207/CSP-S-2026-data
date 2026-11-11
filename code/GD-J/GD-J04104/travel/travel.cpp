#include<bits/stdc++.h>
using namespace std;
string rc,xc,cz,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>cz>>xc>>xz;
	if(rc==xc){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
		if(cz[0]==xz[0]&&cz[1]==xz[1]){
			cout<<1;
			if(cz[2]=='A'||cz[2]=='B'||cz[2]=='C'){
				if(xz[2]=='A'||xz[2]=='B'||xz[2]=='C'){
					cout<<1;
					int a=cz[2];
					int b=xz[2];
					if(a==b+1||a==b-1){
						cout<<1;
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}else{
					cout<<0<<0;
					return 0;
				}
			}else if(cz[2]=='D'&&xz[2]=='F'){
					cout<<1<<1;
					return 0;
				}else if(xz[2]=='D'&&cz[2]=='F'){
					cout<<1<<1;
					return 0;
				}else{
					cout<<0<<0;
					return 0;
				}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	return 0;
}
