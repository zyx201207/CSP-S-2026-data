#include<bits/stdc++.h>
using namespace std;
int a,b,m,n;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>x>>b>>n>>y;
	if(a==b){
		cout<<1;
		if(m==n){
			cout<<1;
			if(x>='D'&&y>='D'){
				cout<<1;
				if(x-y==1||x-y==-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(x<='C'&&y<='C'){
				cout<<1;
				if(x-y==1||x-y==-1){
					cout<<1;
				}else{
					cout<<0;
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
