#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if((a1[0]-'0'+a1[1]-'0')!=(b1[0]-'0'+b1[1]-'0')){
		cout<<0<<0<<0<<0;
	}else{
		cout<<1;
		if((a2[0]-'0'+a2[1]-'0')!=(b2[0]-'0'+b2[1]-'0')){
			cout<<0<<0<<0;
		}else{
			cout<<1;
			if((a2[2]-'0'+b2[2]-'0')>('A'-'0'+'C'-'0')&&(a2[2]-'0'+b2[2]-'0')<('D'-'0'+'E'-'0')){
				cout<<0<<0;
			}else{
				cout<<1;
				if((a2[2]-'0')-(b2[2]-'0')==1||(a2[2]-'0')-(b2[2]-'0')==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}

