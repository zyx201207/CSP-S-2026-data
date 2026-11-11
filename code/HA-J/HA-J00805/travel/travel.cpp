#include<bits/stdc++.h>
using namespace std;
string ax,bx,ar,br;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ar>>br>>ax>>bx;
	if(ar==ax){
		cout<<1;
			if(bx[0]==br[0]&&bx[1]==br[1]){
				cout<<1;
				if(max(br[2],bx[2])>='D'){
					if(max(br[2],bx[2])=='D'){
						cout<<0<<0;
					}else{
						if(min(br[2],bx[2])=='D'){
							cout<<1<<1;
						}
					}
				}else{
					cout<<1;
					if(br[2]-bx[2]==1||br[2]-bx[2]==-1){
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}else{
				cout<<0<<0<<0;
			}
	}else{
		cout<<0<<0<<0<<0;
	}
}
