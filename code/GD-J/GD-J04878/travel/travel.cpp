#include<bits/stdc++.h>
using namespace std;
char n,p,c,a,ni,ci;
char cq,cw,ce,nq,nw,ne;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>p;
	cin>>nq>>nw>>ne;
	cin>>c>>a;
	cin>>cq>>cw>>ce;
	ni=ne+1;
	ci=ce+1;
	if(n==c&&p==a){
		cout<<"1";
		if(cq==nq&&nw==cw){
			cout<<"1";
			if(ne<='C'&&ce<='C'){
				cout<<"1";
				if(ni==ce||ne==ci){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				if(ne>'C'&&ce>'C'){
					cout<<"1";
					if(ni==ce||ne==ci){
					cout<<"1";
				}
				else{
					cout<<"0";
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
