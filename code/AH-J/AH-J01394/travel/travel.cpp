#include <bits/stdc++.h>
using namespace std;
#define int long long
int xi1,pai1,xi2,pai2;
char c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld%c %lld %lld%c",&xi1,&pai1,&c1,&xi2,&pai2,&c2);
	if(xi1==xi2){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D')){
				cout<<1;
				if(c1==c2+1||c1==c2-1){
					cout<<1;
				}else {
					cout<<0;
				}
			}else {
				cout<<"00";
			}
		}else {
			cout<<"000";
		}
	}else {
		cout<<"0000";
	}
	return 0;
} 
