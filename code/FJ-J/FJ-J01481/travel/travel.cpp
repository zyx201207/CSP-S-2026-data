#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b,c,d;
	string cp;
	string pc;
	string cnm="ABCDF";
	cin>>a>>pc>>b>>cp;
	if(a==b){
		cout<<"1";
		if(cp[0]==pc[0]){
			c++;
		}
		if(cp[1]==pc[1]){
			c++;
		}
		if(c==2){
			cout<<"1";
			if(pc[2]==cnm[0]){
				if(pc[2]==cp[2]-1){
					cout<<"11";
				}
				else if(pc[2]==cp[2]-2){
					cout<<"10";
				}
				else{
					cout<<"00";
				}
			}
			if(pc[2]==cnm[1]){
				if(pc[2]==cp[2]-1){
					cout<<"11";
				}
				else if(pc[2]==cp[2]+1){
					cout<<"11";
				}
				else{
					cout<<"00";
				}
			}
			if(pc[2]==cnm[2]){
				if(pc[2]==cp[2]+1){
					cout<<"11";
					}
				else if(pc[2]==cp[2]+2){
					cout<<"10";
				}
				else{
					cout<<"00";
				}
			}
			if(pc[2]==cnm[3]){
					if(pc[2]==cp[2]-1){
						cout<<"11";
					}
					else{
						cout<<"00";
					}
			}
			if(pc[2]==cnm[4]){
					if(pc[2]==cp[2]+2){
						cout<<"11";
					}
					else{
						cout<<"00";
					}
			}
		}
		else {
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
return 0;
}

