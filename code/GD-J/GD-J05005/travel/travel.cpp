#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,ax,b,bx,pa,pb;
	cin>>a>>ax>>b>>bx;
	for(int i=0;i<=1;i++){
		pa[i]=ax[i];
		pb[i]=bx[i];
	}

	if(a==b){
		cout<<1;
		if(pa[0]==pb[0]&&pa[1]==pb[1]){
			cout<<"1";
			if(ax[2]=='A'||ax[2]=='B'||ax[2]=='C'){
				if(bx[2]=='A'||bx[2]=='B'||bx[2]=='C'){
					cout<<1;
					if(ax[2]+1==bx[2]||ax[2]-1==bx[2]){
						cout<<1;
						return 0;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			if(ax[2]=='D'||ax[2]=='F'){
				if(bx[2]=='D'||bx[2]=='F'&&ax[2]!=bx[2]){
					cout<<1;
					if(ax[2]+1==bx[2]||bx[2]+1==ax[2]){
						cout<<"1";
						return 0;
					}
					else{
						cout<<0;
						return 0;
					}
				}
				else{
					cout<<"00";
					return 0;
				}
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
}
