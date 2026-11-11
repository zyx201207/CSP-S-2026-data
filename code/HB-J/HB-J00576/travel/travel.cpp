#include<bits/stdc++.h>
using namespace std;
int n,m;
string q,w;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>q>>m>>w;
	int a=(q[0]-'0')*10+(q[1]-'0');
	int b=(w[0]-'0')*10+(w[1]-'0');
	char z=q[2];
	char c=w[2];
	if(n==m){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if((z<='C'&&c<='C')||(z>'C'&&c>'C')){
				cout<<"1";
				if(z-1==c||z+1==c){
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
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
