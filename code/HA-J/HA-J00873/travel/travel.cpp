#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<1;
		if(rs[0]==xs[0]&&rs[1]==xs[1]){
			cout<<1;
			if(rs[2]>='A'&&rs[2]<='C'){
				if(xs[2]>='A'&&xs[2]<='C'){
					cout<<1;
					if(rs[2]+1==xs[2]||xs[2]+1==rs[2]){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<"00";
				}
			}else{
				if(xs[2]=='D'||xs[2]=='F'){
					cout<<"11";
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
