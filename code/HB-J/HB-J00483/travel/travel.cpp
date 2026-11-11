#include<bits/stdc++.h>
using namespace std;
struct people{
	string xiang;
	string zuo;
}r,x;
int main(void){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.xiang>>r.zuo>>x.xiang>>x.zuo;
	if(r.xiang==x.xiang){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r.xiang==x.xiang){
		if(r.zuo[0]==x.zuo[0] && r.zuo[1]==x.zuo[1]){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(r.xiang==x.xiang){
		if(r.zuo[0]==x.zuo[0] && r.zuo[1]==x.zuo[1]){
			if((r.zuo[2]<='C' && x.zuo[2]<='C') || (r.zuo[2]>='D' && x.zuo[2]>='D')){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(r.xiang==x.xiang){
		if(r.zuo[0]==x.zuo[0] && r.zuo[1]==x.zuo[1]){
			if((r.zuo[2]<='C' && x.zuo[2]<='C') || (r.zuo[2]>='D' && x.zuo[2]>='D')){
				if(r.zuo[2]-x.zuo[2]==1 || x.zuo[2]-r.zuo[2]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
