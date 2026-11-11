#include<bits/stdc++.h>
using namespace std;
struct a{
	int n;
	char m;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r,x;
	a rr,xx;
	cin>>r>>rr.n>>rr.m>>x>>xx.n>>xx.m;
	if(r==x){
		cout<<1;
		if(rr.n==xx.n){
			cout<<1;
			if((rr.m=='F' and xx.m=='D') or rr.m=='D' and xx.m=='F'){
				cout<<11;
			}
			if(rr.m=='C'){
				if(xx.m=='B' or xx.m=='A'){
					cout<<1;
					if(xx.m=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
			if(rr.m=='B'){
				if(xx.m=='C' or xx.m=='A'){
					cout<<11;
				}
				else{
					cout<<0<<0;
				}
			}
			if(rr.m=='A'){
				if(xx.m=='B' or xx.m=='C'){
					cout<<1;
					if(xx.m=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<0<<0;
				}
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
