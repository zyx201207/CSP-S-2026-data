#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int rc=0,xc=0;
	char r[3],x[3];
	cin>>rc>>r>>xc>>x;
	if(rc==xc){
		cout<<1;
		if(r[0]==x[0]&&r[1]==x[1]){
			cout<<1;
			if(r[2]=='A'||r[2]=='B'||r[2]=='C'){
				if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
					cout<<1;
					if(r[2]-x[2]==1||x[2]-r[2]==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
			if(r[2]=='D'||r[2]=='F'){
				if(x[2]=='D'||x[2]=='F'){
					cout<<1;
					if(r[2]-x[2]==2||x[2]-r[2]==2){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<"00";
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
