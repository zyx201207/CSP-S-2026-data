#include<bits/stdc++.h>
using namespace std;
int n,m,na,ma,f=0,fa=0;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>na>>a>>m>>ma>>b;
	if(n==m){
		cout<<'1';
		fa=1;
	}
	else{
		cout<<'0';
	}
	if(fa){
		if(na==ma){
			cout<<'1';
			f=1;
		}
		else{
			cout<<'0';
		}
	
		if(f){
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				cout<<'1';
			}
			else{
				cout<<'0';
			}	
		}
		else{
			cout<<'0';
		}
	
		if(f){
			if(a+1==b){
				if(a=='C'){
					cout<<'0';
				}
				else{
					cout<<'1';
				}
			}
			else if(b+1==a){
				if(b=='C'){
					cout<<'0';
				}
				else{
					cout<<'1';
				}
			}
			else{
				cout<<'0';
			}
		}
		else{
			cout<<'0';
		}		
	}
	else{
		cout<<"000";
	}
}
