#include<bits/stdc++.h>
using namespace std;
int x,r,xp,rp;
string xs,rs,xt,rt;
char xx,rr;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>xs>>r>>rs;
    xt=xs[0]+xs[1];
    rt=rs[0]+rs[1];
    xx=xs[2];
    rr=rs[2];
    if(x==r){
    	if(xt==rt){
    		if((xx=='A'&&rr=='B')||(xx=='B'&&rr=='A')||(xx=='A'&&rr=='C')||(xx=='C'&&rr=='A')||(xx=='B'&&rr=='C')||(xx=='C'&&rr=='B')||(xx=='D'&&rr=='F')||(xx=='F'&&rr=='D')){
    			if((xx=='A'&&rr=='B')||(xx=='B'&&rr=='A')||(xx=='B'&&rr=='C')||(xx=='C'&&rr=='B')||(xx=='D'&&rr=='F')||(xx=='F'&&rr=='D')){
    				cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
