#include <bits/stdc++.h>
using namespace std;
char rc[3],rz[4],xc[3],xz[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc[1]>>rc[2]>>rz[1]>>rz[2]>>rz[3]>>xc[1]>>xc[2]>>xz[1]>>xz[2]>>xz[3];
	if(rc[1]==xc[1] && rc[2]==xc[2]){
		cout<<1;
		if(xz[1]==rz[1] && xz[2]==rz[2]){
			cout<<1;
			if((xz[3]=='A'||xz[3]=='B'||xz[3]=='C')&&(rz[3]=='A'||rz[3]=='B'||rz[3]=='C')){
				cout<<1;
				char a=rz[3],b=xz[3];
				if((a=='A' && b=='B')||(a=='B' && b=='A')||(a=='C' && b=='B')||(a=='B' && b=='C')){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((rz[3]=='D' || rz[3]=='F') && (xz[3]=='F' || xz[3]=='D')){
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
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
