#include<bits/stdc++.h>
using namespace std;
char cr[2],sr[3],cx[2],sx[3];
int x[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<2;i++){
		if(cr[i]!=cx[i]){cout<<0<<0<<0<<0;break;}
		if(i==1){
		    for(int i=0;i<2;i++){
			    if(sr[i]!=sx[i]){cout<<1<<0<<0<<0;break;}
			    if(i==1){
			    	int u=sr[2]-'A',v=sx[2]-'A';
			    	x[u]=1;
					x[v]=1;
					if(x[0]+x[1]+x[2]!=2&&x[3]+x[5]!=2){cout<<1<<1<<0<<0;break;}
					int l=sr[2],r=sx[2];
					if(l+1!=r&&r+1!=l){cout<<1<<1<<1<<0;break;}
					cout<<1<<1<<1<<1;
				}
			}
		}
	}
	return 0;
}
