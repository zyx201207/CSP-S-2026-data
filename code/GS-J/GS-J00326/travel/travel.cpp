#include<bits/stdc++.h>
using namespace std;
struct c{
	int a;
	string b;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	c d[2];
	for(int i=0;i<2;i++){
		cin>>d[i].a>>d[i].b;
	}
	if(d[0].a==d[1].a){
		cout<<1;
		if(d[0].b[0]==d[1].b[0] && d[0].b[1]==d[1].b[1]){
			cout<<1;
			if((d[0].b[2]>='A'&&d[0].b[2]<='C'&&d[1].b[2]>='A'&&d[1].b[2]<='C')||(d[0].b[2]>='D'&&d[0].b[2]<='F'&&d[1].b[2]>='D'&&d[1].b[2]<='F')){
				cout<<1;
				if((int)(d[0].b[2]-d[1].b[2])==-1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
