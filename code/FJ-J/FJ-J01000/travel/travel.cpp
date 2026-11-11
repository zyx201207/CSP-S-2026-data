#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	cin>>e;
	cin>>c>>d;
	cin>>f;
	if(e=='F'){
		e='E';
	}
	if(f=='F'){
		f='E';
	}
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(abs(e-f)<=2){
				if(e=='C'  && f=='D' || e=='C' && f=='E' || e=='B' && f=='D'){
					cout<<0<<0;
				}
				else{
					cout<<1;
					if(abs(e-f)<=1){
						cout<<1;
					}
					else{
						cout<<0;
					}
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
