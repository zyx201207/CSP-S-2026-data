#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx,cy;
	string zx,zy;
	int x,y;
	cin>>cx>>zx>>cy>>zy;
	x=zx[2]-'A';y=zy[2]-'A';
	if(cx==cy){
		cout<<1;
		if(zx[1]==zy[1] && zx[0]==zy[0]){
			cout<<1;
			if(x<=2){
				if(y<=2){
					cout<<1;
					if(abs(x-y)==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}else{
				if(y>=3){
					cout<<11;
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}


	return 0;
} 
