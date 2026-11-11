#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q,q1,w,w1;
    char e,r;
    cin>>q>>q1>>e>>w>>w1>>r;
    if(q==w){
		cout<<"1";
		if(q1==w1){
			cout<<"1";
			if(e=='A'&&r=='B'||e=='A'&&r=='C'||e=='B'&&r=='C'||e=='B'&&r=='A'||e=='C'&&r=='A'||e=='C'&&r=='B'||e=='A'||e=='D'&&r=='F'||e=='F'&&r=='D'){
				cout<<"1";
				if(e=='D'&&r=='F'||e=='F'&&r=='D'||e=='A'&&r=='B'||e=='B'&&r=='A'||e=='B'&&r=='C'||e=='C'&&r=='B'){
					cout<<"1";
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
