#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int m,n,x,y;
	char a,b;
	cin>>m>>x>>a>>n>>y>>b;
	if(m==n){
		cout<<1;
		if(x==y){
			cout<<1;
			if(a<='c'&&b<='C'){
				cout<<1;
				if(a+1==b||b+1==a){
					cout<<1;
				}
				else{
					cout<<"0";
				}
			}
			else if(a>='D'&&b>='D'){
				cout<<"11";
			}
			else{
				cout<<"00";
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
